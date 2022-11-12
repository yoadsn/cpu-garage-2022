module Starfield_unit #(
	parameter SOURCE_ID = 0,
	parameter STAR_COLOR = 9'b111111111,
	parameter COLOR_DEPTH = 9
)(	
		input		clk,
		input		resetN,
		input						frame,
		
		input		[11:0]	Wheel,

		// draw manager interface
		input		  	write_source_sel,
		input		    write_awaited,
		output      write_active,
		output	[COLOR_DEPTH-1:0]  write_color_data,
		output	[9:0]  write_x_addr,
		output	[9:0]  write_y_addr
	);


	// Derived from system native resolution
	parameter NATIVE_DRAW_WIDTH = 640;
	parameter NATIVE_DRAW_HEIGHT = 480;
	parameter TOTAL_PIXELS = NATIVE_DRAW_WIDTH * NATIVE_DRAW_HEIGHT;
	// Control internal drawing resolution
	parameter DRAW_DOWN_SCALE_FACTOR = 1; // Multiples of 2 only are allowed !!! NOT SUPPORTED WITH DRAW MGR! DONT CHANGE FROM 1
	parameter DRAW_WIDTH = NATIVE_DRAW_WIDTH >> $clog2(DRAW_DOWN_SCALE_FACTOR);
	parameter DRAW_WIDTH_HALF = DRAW_WIDTH >> 1;
	parameter DRAW_HEIGHT = NATIVE_DRAW_HEIGHT >> $clog2(DRAW_DOWN_SCALE_FACTOR);
	parameter DRAW_HEIGHT_HALF = DRAW_HEIGHT >> 1;

	parameter STARS_COUNT = 50;
	parameter STARS_SPEED = 5; // Z axis change per frame
	parameter DRAW_TO_SPACE_FACTOR = 10;
	parameter SPACE_WIDTH = NATIVE_DRAW_WIDTH * DRAW_TO_SPACE_FACTOR;
	parameter SPACE_WIDTH_HALF = SPACE_WIDTH >> 1;
	parameter SPACE_HEIGHT = NATIVE_DRAW_HEIGHT * DRAW_TO_SPACE_FACTOR;
	parameter SPACE_HEIGHT_HALF = SPACE_HEIGHT >> 1;
	parameter SPACE_DEPTH = 500;
	// Width is larger than height - so should be enough to contain both coords
	localparam SPACE_COORD_ADDRW = $clog2(SPACE_WIDTH);
	parameter FOCAL_LENGTH = 6;

	// (Stars Count) X (x or y or z) X (position within star space)
	// TODO - why do we need extra 2 bits here to lose the "center artifact?"
	logic [SPACE_COORD_ADDRW+1:0] star_locs_x [0:STARS_COUNT-1];
	logic [SPACE_COORD_ADDRW+1:0] star_locs_y [0:STARS_COUNT-1];
	logic [SPACE_COORD_ADDRW+1:0] star_locs_z [0:STARS_COUNT-1];

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
		PROJECT_STARS,
		PROJECT_DONE,
		DRAW_STARS
	} sf_state, sf_state_next;
	logic [$clog2(STARS_COUNT)-1:0] star_addr, star_addr_next;
	always_comb begin
		lfsr_reset = 0;
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
				sf_state_next = star_addr < STARS_COUNT - 1 ? UPDATE_STARS_LOC : PROJECT_STARS;
				star_addr_next = star_addr < STARS_COUNT - 1 ? star_addr + 1 : 0;
			end

			PROJECT_STARS: begin
				sf_state_next = star_addr < STARS_COUNT - 1 ? PROJECT_STARS : PROJECT_DONE;
				star_addr_next = star_addr < STARS_COUNT - 1 ? star_addr + 1 : 0;
			end

			PROJECT_DONE: begin
				sf_state_next = write_source_sel == SOURCE_ID && write_awaited ? DRAW_STARS : PROJECT_DONE;
			end

			DRAW_STARS: begin
				sf_state_next = DRAW_STARS;
				star_addr_next = star_addr < STARS_COUNT - 1 ? star_addr + 1 : 0;
				if (star_addr == STARS_COUNT - 1) sf_state_next = UPDATE_STARS_LOC;
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
	logic [9:0] stars_draw_buffer_x [0:STARS_COUNT-1];
	logic [9:0] stars_draw_buffer_y [0:STARS_COUNT-1];

	// Draw Starfield onto Active framebuffer
	always_ff @ (posedge clk) begin
		case (sf_state)
			INIT_STARS: begin
				// Initialize curr star with 3d loc
				lfsr_en <= 1;
				star_locs_x[star_addr] <= lfsr_x % SPACE_WIDTH_HALF; // x
				star_locs_y[star_addr] <= lfsr_y % SPACE_HEIGHT_HALF; // y
				star_locs_z[star_addr] <= lfsr_z % SPACE_DEPTH; // z
			end

			UPDATE_STARS_LOC: begin
				lfsr_en <= 0;
				star_locs_z[star_addr] <= star_locs_z[star_addr] > STARS_SPEED ? star_locs_z[star_addr] - STARS_SPEED : SPACE_DEPTH;
			end

			PROJECT_STARS: begin
				case (star_addr[1:0])
					2'b00: begin
						stars_draw_buffer_x[star_addr] <= DRAW_WIDTH_HALF + star_locs_x[star_addr] * FOCAL_LENGTH / star_locs_z[star_addr];
						stars_draw_buffer_y[star_addr] <= DRAW_HEIGHT_HALF + star_locs_y[star_addr] * FOCAL_LENGTH / star_locs_z[star_addr];
					end
					2'b01: begin
						stars_draw_buffer_x[star_addr] <= DRAW_WIDTH_HALF - star_locs_x[star_addr] * FOCAL_LENGTH / star_locs_z[star_addr];
						stars_draw_buffer_y[star_addr] <= DRAW_HEIGHT_HALF + star_locs_y[star_addr] * FOCAL_LENGTH / star_locs_z[star_addr];
					end
					2'b10: begin
						stars_draw_buffer_x[star_addr] <= DRAW_WIDTH_HALF - star_locs_x[star_addr] * FOCAL_LENGTH / star_locs_z[star_addr];
						stars_draw_buffer_y[star_addr] <= DRAW_HEIGHT_HALF - star_locs_y[star_addr] * FOCAL_LENGTH / star_locs_z[star_addr];
					end
					2'b11: begin
						stars_draw_buffer_x[star_addr] <= DRAW_WIDTH_HALF + star_locs_x[star_addr] * FOCAL_LENGTH / star_locs_z[star_addr];
						stars_draw_buffer_y[star_addr] <= DRAW_HEIGHT_HALF - star_locs_y[star_addr] * FOCAL_LENGTH / star_locs_z[star_addr];
					end
				endcase
				
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
		endcase
	end

	assign write_active = write_source_sel == SOURCE_ID ? (sf_state == DRAW_STARS) : 'z;
	assign write_color_data = write_source_sel == SOURCE_ID ? STAR_COLOR : 'z;
	assign write_x_addr = write_source_sel == SOURCE_ID ? stars_draw_buffer_x[star_addr] : 'z;
	assign write_y_addr = write_source_sel == SOURCE_ID ? stars_draw_buffer_y[star_addr] : 'z;

endmodule