module Frame_manager #(
	parameter MAX_WRITE_SOURCE = 1,
	parameter DRAW_WIDTH = 640,
	parameter DRAW_HEIGHT = 480,
	parameter SCALE_DOWN_FACTOR = 2, // 2^x
	parameter COLOR_DEPTH = 9
)(
	
	input						clk,
	input						resetN,
	input						frame,
	input		[COLOR_DEPTH-1:0]	write_color_data,
	input		[$clog2(DRAW_WIDTH)-1:0]	write_x_addr,
	input		[$clog2(DRAW_HEIGHT)-1:0]	write_y_addr,
	input		logic		write_active,
	output	reg	write_awaited,
	output	reg	write_source_sel,

  	input   [$clog2(DRAW_WIDTH)-1:0] read_x_addr,
  	input   [$clog2(DRAW_HEIGHT)-1:0] read_y_addr,
  	output	[COLOR_DEPTH-1:0] read_color_data
	);

localparam SCALE_DOWN_SHR = $clog2(SCALE_DOWN_FACTOR);
localparam SCALED_DRAW_WIDTH = DRAW_WIDTH >> SCALE_DOWN_SHR;
localparam SCALED_DRAW_HEIGHT = DRAW_HEIGHT >> SCALE_DOWN_SHR;
localparam FB_DEPTH = SCALED_DRAW_WIDTH * SCALED_DRAW_HEIGHT;
localparam FB_ADDRW = $clog2(FB_DEPTH);

logic active_framebuffer;
logic [FB_ADDRW-1:0] fb_read_addr;
logic [FB_ADDRW-1:0] fb_write_addr;
reg [COLOR_DEPTH-1:0] stored_read_color_fb_0;
reg [COLOR_DEPTH-1:0] stored_read_color_fb_1;

always_comb begin
	fb_read_addr = (read_y_addr >> SCALE_DOWN_SHR) * SCALED_DRAW_WIDTH + (read_x_addr >> SCALE_DOWN_SHR);
	fb_write_addr = (write_y_addr >> SCALE_DOWN_SHR) * SCALED_DRAW_WIDTH + (write_x_addr >> SCALE_DOWN_SHR);
end

/* bram_sdp #(
		.WIDTH(12),
		.DEPTH(FB_DEPTH)
	) stars_draw_fb_0 (
		.clk_write(clk),
		.clk_read(clk),
		.we(write_active && active_framebuffer), // FB 1 active for reading - write to 0
		.addr_write(write_y_addr * DRAW_WIDTH + write_x_addr),
		.addr_read(fb_read_addr),
		.data_in(write_color_data),
		.data_out(stored_read_color_fb_0)
	); */

ram_2p	#(
		.WIDTH(COLOR_DEPTH),
		.DEPTH(FB_DEPTH)
	) stars_draw_fb_0 (
	.data ( write_color_data ),
	.rdaddress ( fb_read_addr ),
	.rdclock ( clk ),
	.wraddress ( fb_write_addr ),
	.wrclock ( clk ),
	.wren ( write_active && active_framebuffer ), // FB 1 active for reading - write to 0
	.q ( stored_read_color_fb_0 )
);

	
/* bram_sdp #(
		.WIDTH(12),
		.DEPTH(FB_DEPTH)
	) stars_draw_fb_1 (
		.clk_write(clk),
		.clk_read(clk),
		.we(write_active && ~active_framebuffer), // FB 0 active for reading - write to 1
		.addr_write(write_y_addr * DRAW_WIDTH + write_x_addr),
		.addr_read(fb_read_addr),
		.data_in(write_color_data),
		.data_out(stored_read_color_fb_1)
	); */

ram_2p	#(
		.WIDTH(COLOR_DEPTH),
		.DEPTH(FB_DEPTH)
	) stars_draw_fb_1 (
	.data ( write_color_data ),
	.rdaddress ( fb_read_addr ),
	.rdclock ( clk ),
	.wraddress ( fb_write_addr ),
	.wrclock ( clk ),
	.wren ( write_active && ~active_framebuffer ), // FB 0 active for reading - write to 1
	.q ( stored_read_color_fb_1 )
);

// Write side state machine
enum {
		SIGNAL_SOURCE,
		AWAIT_WRITE,
		WRITING_ACTIVE,
		WRITING_DONE,
		AWAIT_SWAP_FRAMES
} wsrc_state, wsrc_state_next;
logic next_write_source_sel = 0;
logic next_active_framebuffer;

always_comb begin
	next_write_source_sel = write_source_sel;
	wsrc_state_next = SIGNAL_SOURCE;
	next_active_framebuffer = active_framebuffer;

	case (wsrc_state)
		SIGNAL_SOURCE: begin
			wsrc_state_next = AWAIT_WRITE;
		end

		AWAIT_WRITE: begin
			wsrc_state_next = write_active ? WRITING_ACTIVE : AWAIT_WRITE;
		end

		WRITING_ACTIVE: begin
			wsrc_state_next = write_active ? WRITING_ACTIVE : WRITING_DONE;
		end

		WRITING_DONE: begin
			if (write_source_sel == MAX_WRITE_SOURCE) begin
					wsrc_state_next = AWAIT_SWAP_FRAMES;
					next_write_source_sel = 0;
			end else begin
				wsrc_state_next = SIGNAL_SOURCE;
				next_write_source_sel = write_source_sel + 1;
			end
		end

		AWAIT_SWAP_FRAMES: begin
			wsrc_state_next = frame ? SIGNAL_SOURCE : AWAIT_SWAP_FRAMES;
			next_active_framebuffer = frame ? ~active_framebuffer : active_framebuffer;
		end
	endcase

	if (~resetN) begin
		next_write_source_sel = 0;
		wsrc_state_next = SIGNAL_SOURCE;
		next_active_framebuffer = 0;
	end
end

// update source write state
always_ff @(posedge clk) begin
	wsrc_state <= wsrc_state_next;
	write_source_sel <= next_write_source_sel;
	active_framebuffer <= next_active_framebuffer;
end

// Signal sources that writes are awaited
always_ff @(posedge clk or negedge resetN) begin
	if (~resetN) begin
		write_awaited <= 0;
	end
	else begin
		case (wsrc_state)
			SIGNAL_SOURCE: begin
				write_awaited <= 1;
			end

			WRITING_ACTIVE: begin
				write_awaited <= 0;
			end
		endcase
	end
end

// Read side state machine
// Adds 1 cycle latency for bram access - as expected by the draw pipeline
assign read_color_data = active_framebuffer ? stored_read_color_fb_1 : stored_read_color_fb_0;
	
endmodule