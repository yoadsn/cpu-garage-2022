module Starfield_unit #(
	parameter SOURCE_ID = 0,
	parameter STAR_COLOR = 9'b111111111
)(	
		input		clk,
		input		resetN,
		input		frame,
		input		[9:0] SW,
		
		input		[3:0]	tilt_amount_x,
		input				tilt_direction_x,
		input		[3:0]	tilt_amount_y,
		input				tilt_direction_y,

		// draw manager interface
		input		[SOURCE_SEL_ADDRW-1:0]  	write_source_sel,
		input		    write_awaited,
		output      write_active,
		output	[COLOR_DEPTH-1:0]  write_color_data,
		output		write_transparent,
		output	[DRAW_WIDTH_ADDRW-1:0]	write_x_addr,
		output	[DRAW_HEIGHT_ADDRW-1:0]	write_y_addr
	);

	`include "frame_manager.h"

	// Derived from system native resolution
	localparam signed DRAW_WIDTH_HALF = DRAW_WIDTH >> 1;
	localparam signed DRAW_HEIGHT_HALF = DRAW_HEIGHT >> 1;

	localparam STARS_COUNT = 50;
	localparam STARS_ADDRW = $clog2(STARS_COUNT);
	localparam STARS_X_SPEED = 10; // Z axis change per frame
	localparam STARS_Y_SPEED = 10; // Z axis change per frame
	localparam STARS_Z_SPEED = 5; // Z axis change per frame
	localparam DRAW_TO_SPACE_FACTOR = 40;
	localparam SPACE_WIDTH = DRAW_WIDTH * DRAW_TO_SPACE_FACTOR;
	localparam signed SPACE_WIDTH_HALF = SPACE_WIDTH >> 1;
	localparam SPACE_HEIGHT = DRAW_HEIGHT * DRAW_TO_SPACE_FACTOR;
	localparam signed SPACE_HEIGHT_HALF = SPACE_HEIGHT >> 1;
	localparam SPACE_DEPTH = 1000;
	localparam SPACE_DEPTH_ADDRW = $clog2(SPACE_DEPTH);
	// Width is larger than height - so should be enough to contain both coords
	localparam signed FOCAL_LENGTH = 10;
	
	localparam LSFR_ADDRW = 15;
	localparam LSFR_HALF_RANGE = {1'b1, {(LSFR_ADDRW - 1){1'b0}}}; // 1 SHL LSFR_ADDRW-1 times

	// (Stars Count) X (x or y or z) X (position within star space)
	// TODO - why do we need extra 2 bits here to lose the "center artifact?"
	shortint star_locs_x [0:STARS_COUNT-1];
	shortint star_locs_y [0:STARS_COUNT-1];
	shortint star_locs_z [0:STARS_COUNT-1];

	int dbg_where;

	logic lfsr_en;
	logic lfsr_reset;
	logic [LSFR_ADDRW-1:0] lfsr_x;
	lfsr #(  // Up to about 4000
			.LEN(LSFR_ADDRW),
			.TAPS(15'b110000000000000)
	) lsfr_x_loc (
			.clk(clk),
			.rst(lfsr_reset),
			.en(lfsr_en),
			.seed(5555),
			.sreg(lfsr_x)
	);

	logic [LSFR_ADDRW-1:0] lfsr_y;
	lfsr #(  // Up to about 4000
			.LEN(LSFR_ADDRW),
			.TAPS(15'b110000000000000)
			//.TAPS(12'b111000001000)
	) lsfr_y_loc (
			.clk(clk),
			.rst(lfsr_reset),
			.en(lfsr_en),
			.seed(23),
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
			.seed(323),
			.sreg(lfsr_z)
	);

	enum {
		INIT_STARS_SEED,
		INIT_STARS,
		INIT_STARS_DONE,
		PROJECT_STARS,
		REPLACE_STARS,
		REPLACE_DONE,
		DRAW_STARS
	} sf_state, sf_state_next;
	logic [STARS_ADDRW-1:0] star_addr, star_addr_next;
	always_comb begin
		star_addr_next = 0;
		sf_state_next = INIT_STARS_SEED;

		case (sf_state)
			INIT_STARS_SEED: begin
				sf_state_next = INIT_STARS;
			end

			INIT_STARS: begin
				sf_state_next = star_addr < STARS_COUNT - 1 ? INIT_STARS : INIT_STARS_DONE;
				star_addr_next = star_addr < STARS_COUNT - 1 ? star_addr + 1 : 0;
			end

			INIT_STARS_DONE: begin
				sf_state_next = PROJECT_STARS;
			end

			PROJECT_STARS: begin
				sf_state_next = star_addr < STARS_COUNT - 1 ? PROJECT_STARS : REPLACE_STARS;
				star_addr_next = star_addr < STARS_COUNT - 1 ? star_addr + 1 : 0;
			end

			REPLACE_STARS: begin
				sf_state_next = star_addr < STARS_COUNT - 1 ? REPLACE_STARS : REPLACE_DONE;
				star_addr_next = star_addr < STARS_COUNT - 1 ? star_addr + 1 : 0;
			end

			REPLACE_DONE: begin
				sf_state_next = write_source_sel == SOURCE_ID && write_awaited ? DRAW_STARS : REPLACE_DONE;
			end

			DRAW_STARS: begin
				sf_state_next = DRAW_STARS;
				star_addr_next = star_addr < STARS_COUNT - 1 ? star_addr + 1 : 0;
				if (star_addr == STARS_COUNT - 1) sf_state_next = PROJECT_STARS;
			end

			default: sf_state_next = INIT_STARS_SEED;
		endcase

		if (!resetN) begin
			sf_state_next = INIT_STARS_SEED;
			star_addr_next = 0;
		end
	end

	// update starfield state
	always_ff @(posedge clk) begin
		sf_state <= sf_state_next;
		star_addr <= star_addr_next;
		//dbg_where <= active_star_draw_buffer_next;
	end

	// For each star - which screen x,y to draw on?
	// Create a buffer until draw state (pipeline the projections)
	// (Stars Count) X (x or y) X (32 bit coordinate)
	// Signed so we can have out of bound stars - add another bit we have the positive
	// range cover the entire needed draw size
	logic signed [DRAW_WIDTH_ADDRW:0] stars_draw_buffer_x [0:STARS_COUNT-1];
	logic signed [DRAW_HEIGHT_ADDRW:0] stars_draw_buffer_y [0:STARS_COUNT-1];
	logic [2:0] stars_draw_buffer_c [0:STARS_COUNT-1];

	
	wire draw_outbound_star_x_neg = stars_draw_buffer_x[star_addr] < 0;
	wire draw_outbound_star_x_pos = stars_draw_buffer_x[star_addr] >= DRAW_WIDTH;
	wire draw_outbound_star_y_neg = stars_draw_buffer_y[star_addr] < 0;
	wire draw_outbound_star_y_pos = stars_draw_buffer_y[star_addr] >= DRAW_HEIGHT;

	wire star_out_of_draw_range = 
		draw_outbound_star_x_neg ||
		draw_outbound_star_x_pos ||
		draw_outbound_star_y_neg ||
		draw_outbound_star_y_pos;
	
	wire space_outbound_star_x_neg = star_locs_x[star_addr] < -SPACE_WIDTH_HALF;
	wire space_outbound_star_x_pos = star_locs_x[star_addr] > SPACE_WIDTH_HALF;
	wire space_outbound_star_y_neg = star_locs_y[star_addr] < -SPACE_HEIGHT_HALF;
	wire space_outbound_star_y_pos = star_locs_y[star_addr] > SPACE_HEIGHT_HALF;
	
	wire space_outbound_star_z_neg = star_locs_z[star_addr] <= STARS_Z_SPEED;
		
	wire [COLOR_DEPTH-1:0] star_draw_color = {stars_draw_buffer_c[star_addr], stars_draw_buffer_c[star_addr], stars_draw_buffer_c[star_addr]};

	// Draw Starfield onto Active framebuffer
	always_ff @ (posedge clk) begin
		case (sf_state)
			INIT_STARS_SEED: begin
				lfsr_reset <= 1;
			end

			INIT_STARS: begin
				lfsr_reset <= 0;
				lfsr_en <= 1;
				// Initialize curr star with 3d loc
				star_locs_x[star_addr] <= (lfsr_x % SPACE_WIDTH) - SPACE_WIDTH_HALF; // x
				star_locs_y[star_addr] <=  (lfsr_y % SPACE_HEIGHT) - SPACE_HEIGHT_HALF; // y
				star_locs_z[star_addr] <=  lfsr_z % SPACE_DEPTH; // z
			end

			INIT_STARS_DONE: begin
				lfsr_en <= 0;
			end

			PROJECT_STARS: begin
				if (star_locs_x[star_addr] >= 0) begin
					stars_draw_buffer_x[star_addr] <= DRAW_WIDTH_HALF + (star_locs_x[star_addr]) * FOCAL_LENGTH / star_locs_z[star_addr];
				end else begin
					stars_draw_buffer_x[star_addr] <= DRAW_WIDTH_HALF - (0 - star_locs_x[star_addr]) * FOCAL_LENGTH / star_locs_z[star_addr];
				end

				if (star_locs_y[star_addr] >= 0) begin
					stars_draw_buffer_y[star_addr] <= DRAW_HEIGHT_HALF + star_locs_y[star_addr] * FOCAL_LENGTH / star_locs_z[star_addr];
				end else begin
					stars_draw_buffer_y[star_addr] <= DRAW_HEIGHT_HALF - (0 - star_locs_y[star_addr]) * FOCAL_LENGTH / star_locs_z[star_addr];
					end

				//stars_draw_buffer_c[star_addr] <= (star_locs_z[star_addr] <= SPACE_DEPTH * 2 / 3);
				stars_draw_buffer_c[star_addr] <= star_locs_z[star_addr] < SPACE_DEPTH / 2 ? 3'b111 :
																					star_locs_z[star_addr] < SPACE_DEPTH * 2 / 3 ? 3'b110 :
																					3'b100;
																					

				//stars_draw_buffer_c[star_addr] <= 3'b111;
				
				/*case (star_addr[1:0])
					2'b00: begin
						stars_draw_buffer_x[star_addr] <= 60;
						stars_draw_buffer_y[star_addr] <= 0;
					end
					2'b01: begin
						stars_draw_buffer_x[star_addr] <= 10;
						stars_draw_buffer_y[star_addr] <= 20;
					end
					2'b10: begin
						stars_draw_buffer_x[star_addr] <= 20;
						stars_draw_buffer_y[star_addr] <= 40;
					end
					2'b11: begin
						stars_draw_buffer_x[star_addr] <= 30;
						stars_draw_buffer_y[star_addr] <= 60;
					end
				endcase*/
			end

			REPLACE_STARS: begin
				lfsr_en <= 1;

				if (space_outbound_star_x_neg) begin
					star_locs_x[star_addr] <= (lfsr_x % SPACE_WIDTH_HALF);
				end else if (space_outbound_star_x_pos) begin
					star_locs_x[star_addr] <= 0 - (lfsr_x % SPACE_WIDTH_HALF);
				end else if (space_outbound_star_y_neg) begin
					star_locs_y[star_addr] <= (lfsr_y % SPACE_HEIGHT_HALF);
				end else if (space_outbound_star_y_pos) begin
					star_locs_y[star_addr] <= 0 - (lfsr_y % SPACE_HEIGHT_HALF);
				end else begin
					star_locs_x[star_addr] <= tilt_direction_x ? star_locs_x[star_addr] + tilt_amount_x * STARS_X_SPEED : star_locs_x[star_addr] - tilt_amount_x * STARS_X_SPEED;
					star_locs_y[star_addr] <= tilt_direction_y ? star_locs_y[star_addr] + tilt_amount_y * STARS_Y_SPEED : star_locs_y[star_addr] - tilt_amount_y * STARS_Y_SPEED;
				end
				
				if (space_outbound_star_z_neg || star_out_of_draw_range) begin
					star_locs_z[star_addr] <= SPACE_DEPTH - lfsr_z % (SPACE_DEPTH / 3);
					star_locs_x[star_addr] <= (lfsr_x % SPACE_WIDTH) - SPACE_WIDTH_HALF;
					star_locs_y[star_addr] <= (lfsr_y % SPACE_HEIGHT) - SPACE_HEIGHT_HALF;
				end else begin
					star_locs_z[star_addr] <= star_locs_z[star_addr] - STARS_Z_SPEED;
				end
			end

			REPLACE_DONE: begin
				lfsr_en <= 0;
			end
		endcase
	end

	assign write_active = write_source_sel == SOURCE_ID ? (sf_state == DRAW_STARS) : 'z;
	//assign write_color_data = write_source_sel == SOURCE_ID ? (stars_draw_buffer_c[star_addr] ? STAR_COLOR : 9'b011011100) : 'z;
	assign write_color_data = write_source_sel == SOURCE_ID ? star_draw_color : 'z;
	assign write_x_addr = write_source_sel == SOURCE_ID ? stars_draw_buffer_x[star_addr] : 'z;
	assign write_y_addr = write_source_sel == SOURCE_ID ? stars_draw_buffer_y[star_addr] : 'z;
	assign write_transparent = write_source_sel == SOURCE_ID ? star_out_of_draw_range : 'z;

endmodule