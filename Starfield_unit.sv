// Designer: Yoad
// Oct. 2022
// ***********************************************



module Starfield_unit (	
		input		clk,
		input		resetN,
		input		[11:0]	Wheel,
		input		[31:0]	pxl_x,
		input		[31:0]	pxl_y,
		input						frame,
		output	[3:0]		Red,
		output	[3:0]		Green,
		output	[3:0]		Blue,
		output	Draw
	);

	parameter DRAW_WIDTH = 640;
	parameter DRAW_WIDTH_HALF = DRAW_WIDTH >> 1;
	parameter DRAW_HEIGHT = 480;
	parameter DRAW_HEIGHT_HALF = DRAW_HEIGHT >> 1;
	parameter TOTAL_PIXELS = DRAW_WIDTH * DRAW_HEIGHT;

	parameter STARS_COUNT = 4;
	parameter STARS_SPEED = 5; // Z axis change per frame
	parameter DRAW_TO_SPACE_FACTOR = 10;
	parameter SPACE_WIDTH = DRAW_WIDTH * DRAW_TO_SPACE_FACTOR;
	parameter SPACE_WIDTH_HALF = SPACE_WIDTH >> 1;
	parameter SPACE_HEIGHT = DRAW_HEIGHT * DRAW_TO_SPACE_FACTOR;
	parameter SPACE_HEIGHT_HALF = SPACE_HEIGHT >> 1;
	parameter SPACE_DEPTH = 500;
	// Width is larger than height - so should be enough to contain both coords
	localparam SPACE_COORD_ADDRW = $clog2(SPACE_WIDTH);
	parameter FOCAL_LENGTH = 6;

	parameter DRAW_DELAY_CLOCKS = 64'd50_000;

	// Star/xyz/location in 3d space
	localparam STAR_LOC_X_ADDR = 0;
	localparam STAR_LOC_Y_ADDR = 1;
	localparam STAR_LOC_Z_ADDR = 2;
	// (Start Count) X (x or y or z) X (position within star space)
	// TODO - why do we need extra 2 bits here to lose the "center artifact?"
	logic [SPACE_COORD_ADDRW+1:0] star_locs [0:STARS_COUNT-1][0:2];

	logic [31:0] pxl_abs_pos_fixed;
	logic [31:0] pxl_x_fixed;
	logic [31:0] pxl_y_fixed;

	always_comb begin
		// One pixel forward - to compensate for the latency on the drawing mux
		//pxl_abs_pos_fixed = (pxl_x + pxl_y * DRAW_WIDTH + 1) % TOTAL_PIXELS;
		//pxl_x_fixed = pxl_abs_pos_fixed % DRAW_WIDTH;
		//pxl_y_fixed = pxl_abs_pos_fixed / DRAW_WIDTH;
		pxl_x_fixed = pxl_x;
		pxl_y_fixed = pxl_y;
	end

	// For each star - which screen x,y to draw on?
	// Create two buffers and swap them when data is ready for drawing
	// (2 Buffers) X (Stars Count) X (x or y) X (32 bit coordinate)
	parameter STAR_DRAW_X_ADDR = 0;
	parameter STAR_DRAW_Y_ADDR = 1;
	reg [31:0] stars_draw_buffer [0:1][0:STARS_COUNT-1][0:1];

	int dbg_where /*verilator public_flat_rd*/;

	logic lfsr_en;
	logic lfsr_reset;
	logic [11:0] lfsr_x /*verilator public_flat_rd*/;
	lfsr #(  // Up to about 4000
			.LEN(12),
			.TAPS(12'b111000001000)
	) lsfr_x_loc (
			.clk(clk),
			.rst(lfsr_reset),
			.en(lfsr_en),
			.seed(12),  // use default seed
			.sreg(lfsr_x)
	);

	logic [11:0] lfsr_y;
	lfsr #(  // Up to about 4000
			.LEN(12),
			.TAPS(12'b111000001000)
	) lsfr_y_loc (
			.clk(clk),
			.rst(lfsr_reset),
			.en(lfsr_en),
			.seed(53),  // use default seed
			.sreg(lfsr_y)
	);

	logic [10:0] lfsr_z;
	lfsr #(  // Up to about 2000
			.LEN(11),
			.TAPS(11'b10100000000)
	) lsfr_z_loc (
			.clk(clk),
			.rst(lfsr_reset),
			.en(lfsr_en),
			.seed(4000),  // use default seed
			.sreg(lfsr_z)
	);

	enum {
		INIT_STARS_SEED,
		INIT_STARS,
		UPDATE_STARS_LOC,
		DRAW_STARS,
		DRAW_DONE
	} sf_state, sf_state_next;
	logic [$clog2(STARS_COUNT)-1:0] star_addr, star_addr_next;
	// Star draw buffer select
	logic active_star_draw_buffer, active_star_draw_buffer_next;
	always_comb begin
		lfsr_reset = 0;
		active_star_draw_buffer_next = active_star_draw_buffer;
		star_addr_next = 0;
		sf_state_next = INIT_STARS_SEED;

		case (sf_state)
			INIT_STARS_SEED: begin
				lfsr_reset = 1;
				sf_state_next = INIT_STARS;
			end

			INIT_STARS: begin
				sf_state_next = star_addr < STARS_COUNT - 1 ? INIT_STARS : UPDATE_STARS_LOC;
				star_addr_next = star_addr < STARS_COUNT - 1 ? star_addr + 1 : 0;
			end

			UPDATE_STARS_LOC: begin
				sf_state_next = star_addr < STARS_COUNT - 1 ? UPDATE_STARS_LOC : DRAW_STARS;
				star_addr_next = star_addr < STARS_COUNT - 1 ? star_addr + 1 : 0;
			end

			DRAW_STARS: begin
				sf_state_next = star_addr < STARS_COUNT - 1 ? DRAW_STARS : DRAW_DONE;
				star_addr_next = star_addr < STARS_COUNT - 1 ? star_addr + 1 : 0;
			end

			DRAW_DONE: begin
				// Swap buffers and start over only on new frame
				if (frame) begin
					sf_state_next = UPDATE_STARS_LOC;
					active_star_draw_buffer_next = !active_star_draw_buffer;
				end else begin
					sf_state_next = DRAW_DONE;
				end
			end

			default: sf_state_next = INIT_STARS_SEED;
		endcase

		if (!resetN) begin
			sf_state_next = INIT_STARS_SEED;
			star_addr_next = 0;
			active_star_draw_buffer_next = 0;
		end
	end

	// update starfield state
  always_ff @(posedge clk) begin
		sf_state <= sf_state_next;
		star_addr <= star_addr_next;
		active_star_draw_buffer <= active_star_draw_buffer_next;
		//dbg_where <= active_star_draw_buffer_next;
	end

	// Draw Starfield onto Active framebuffer
	always_ff @ (posedge clk) begin
		case (sf_state)
			INIT_STARS: begin
				// Initialize curr star with 3d loc
				lfsr_en <= 1;
				star_locs[star_addr][STAR_LOC_X_ADDR] <= lfsr_x % SPACE_WIDTH_HALF; // x
				star_locs[star_addr][STAR_LOC_Y_ADDR] <= lfsr_y % SPACE_HEIGHT_HALF; // y
				star_locs[star_addr][STAR_LOC_Z_ADDR] <= lfsr_z % SPACE_DEPTH; // z
			end

			UPDATE_STARS_LOC: begin
				lfsr_en <= 0;
				star_locs[star_addr][STAR_LOC_Z_ADDR] <= star_locs[star_addr][STAR_LOC_Z_ADDR] > 2 ? star_locs[star_addr][STAR_LOC_Z_ADDR] - STARS_SPEED : SPACE_DEPTH;
			end

			DRAW_STARS: begin
				case (star_addr[1:0])
					2'b00: begin
						stars_draw_buffer[!active_star_draw_buffer][star_addr][STAR_DRAW_X_ADDR] <= DRAW_WIDTH_HALF + star_locs[star_addr][STAR_LOC_X_ADDR] * FOCAL_LENGTH / star_locs[star_addr][STAR_LOC_Z_ADDR];
						stars_draw_buffer[!active_star_draw_buffer][star_addr][STAR_DRAW_Y_ADDR] <= DRAW_HEIGHT_HALF + star_locs[star_addr][STAR_LOC_Y_ADDR] * FOCAL_LENGTH / star_locs[star_addr][STAR_LOC_Z_ADDR];
					end
					2'b01: begin
						stars_draw_buffer[!active_star_draw_buffer][star_addr][STAR_DRAW_X_ADDR] <= DRAW_WIDTH_HALF - star_locs[star_addr][STAR_LOC_X_ADDR] * FOCAL_LENGTH / star_locs[star_addr][STAR_LOC_Z_ADDR];
						stars_draw_buffer[!active_star_draw_buffer][star_addr][STAR_DRAW_Y_ADDR] <= DRAW_HEIGHT_HALF + star_locs[star_addr][STAR_LOC_Y_ADDR] * FOCAL_LENGTH / star_locs[star_addr][STAR_LOC_Z_ADDR];
					end
					2'b10: begin
						stars_draw_buffer[!active_star_draw_buffer][star_addr][STAR_DRAW_X_ADDR] <= DRAW_WIDTH_HALF - star_locs[star_addr][STAR_LOC_X_ADDR] * FOCAL_LENGTH / star_locs[star_addr][STAR_LOC_Z_ADDR];
						stars_draw_buffer[!active_star_draw_buffer][star_addr][STAR_DRAW_Y_ADDR] <= DRAW_HEIGHT_HALF - star_locs[star_addr][STAR_LOC_Y_ADDR] * FOCAL_LENGTH / star_locs[star_addr][STAR_LOC_Z_ADDR];
					end
					2'b11: begin
						stars_draw_buffer[!active_star_draw_buffer][star_addr][STAR_DRAW_X_ADDR] <= DRAW_WIDTH_HALF + star_locs[star_addr][STAR_LOC_X_ADDR] * FOCAL_LENGTH / star_locs[star_addr][STAR_LOC_Z_ADDR];
						stars_draw_buffer[!active_star_draw_buffer][star_addr][STAR_DRAW_Y_ADDR] <= DRAW_HEIGHT_HALF - star_locs[star_addr][STAR_LOC_Y_ADDR] * FOCAL_LENGTH / star_locs[star_addr][STAR_LOC_Z_ADDR];
					end
				endcase
			end

			DRAW_DONE: begin
			end
		endcase
	end

	logic draw_i;
	always_comb begin
		draw_i = 0;

		for (int staridx = 0; staridx < STARS_COUNT; staridx = staridx + 1) begin
			draw_i = draw_i || (
				stars_draw_buffer[active_star_draw_buffer][staridx][STAR_DRAW_X_ADDR] == pxl_x_fixed
				&&
				stars_draw_buffer[active_star_draw_buffer][staridx][STAR_DRAW_Y_ADDR] == pxl_y_fixed
			);
		end
	end

	assign Draw = draw_i;
	assign Red = 4'h0;
	assign Green = 4'h0;
	assign Blue = 4'h0;

endmodule