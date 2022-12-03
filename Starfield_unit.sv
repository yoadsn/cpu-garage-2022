module Starfield_unit #(
	parameter SOURCE_ID = SOURCE_SEL_ADDRW'(0),
	parameter STARS_COUNT = 9'd50
)(	
		input		clk,
		input		resetN,
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

	localparam STARS_ADDRW = $clog2(STARS_COUNT);
	localparam STARS_X_SPEED = 10; // X axis change per frame
	localparam STARS_Y_SPEED = 10; // Y axis change per frame
	localparam STARS_Z_SPEED = 5; // Z axis change per frame
	localparam DRAW_TO_SPACE_FACTOR = 40;
	localparam SPACE_WIDTH = 1 << (LSFR_ADDRW - 1);
	localparam SPACE_WIDTH_OFF_LIMIT = SPACE_WIDTH - 100;
	localparam signed SPACE_WIDTH_HALF = SPACE_WIDTH >> 1;
	localparam SPACE_HEIGHT = 1 << (LSFR_ADDRW - 1);
	localparam SPACE_HEIGHT_OFF_LIMIT = SPACE_HEIGHT - 100;
	localparam signed SPACE_HEIGHT_HALF = SPACE_HEIGHT >> 1;
	localparam SPACE_DEPTH = 1000;
	localparam SPACE_DEPTH_ADDRW = $clog2(SPACE_DEPTH);
	// Width is larger than height - so should be enough to contain both coords
	localparam signed FOCAL_LENGTH = 7;
	
	localparam LSFR_ADDRW = 16;
	localparam LSFR_HALF_RANGE = {1'b1, {(LSFR_ADDRW - 1){1'b0}}}; // 1 SHL LSFR_ADDRW-1 times

	wire source_selected = write_source_sel == SOURCE_ID; 

	// (Stars Count) X (x or y or z) X (position within star space)
	// TODO - why do we need extra 2 bits here to lose the "center artifact?"
	shortint star_locs_x [0:STARS_COUNT-1];
	shortint star_locs_y [0:STARS_COUNT-1];
	shortint star_locs_z [0:STARS_COUNT-1];

	logic lfsr_en;
	logic lfsr_reset;
	logic [LSFR_ADDRW-1:0] lfsr_x;
	lfsr #(
			.LEN(LSFR_ADDRW),
			.TAPS(16'b1101000000001000)
	) lsfr_x_loc (
			.clk(clk),
			.rst(lfsr_reset),
			.en(lfsr_en),
			.seed(5555),
			.sreg(lfsr_x)
	);

	logic [LSFR_ADDRW-1:0] lfsr_y;
	lfsr #(
			.LEN(LSFR_ADDRW),
			.TAPS(16'b1101000000001000)
	) lsfr_y_loc (
			.clk(clk),
			.rst(lfsr_reset),
			.en(lfsr_en),
			.seed(23),
			.sreg(lfsr_y)
	);

	logic [10:0] lfsr_z;
	lfsr #(
			.LEN(11),
			.TAPS(11'b10100000000)
	) lsfr_z_loc (
			.clk(clk),
			.rst(lfsr_reset),
			.en(lfsr_en),
			.seed(323),
			.sreg(lfsr_z)
	);


	shortint star_loc_t_x;
	shortint star_loc_t_y;
	shortint star_loc_t_z;
	integer loc_mul_res_t_x;
	integer loc_mul_res_t_y;
	logic signed [DRAW_WIDTH_ADDRW:0] stars_draw_t_x;
	logic signed [DRAW_HEIGHT_ADDRW:0] stars_draw_t_y;
	logic [2:0] stars_draw_t_c;
	logic [COLOR_DEPTH-1:0] star_draw_color_t;
	typedef enum logic [3:0] {
    INIT_STARS_SEED,
		INIT_STARS,
		INIT_STARS_DONE,

		LOAD_STAR_LOCS,
		PROJECT_STAR_MUL,
		PROJECT_STAR_DIV,
		REPLACE_STAR,
		STORE_STAR_DRAW,

		AWAIT_DRAW,
		DRAW_STARS
	} stateType;
	stateType sf_state, sf_state_next;
	logic [STARS_ADDRW-1:0] star_addr, star_addr_next;
	always_comb begin
		star_addr_next = star_addr;
		sf_state_next = INIT_STARS_SEED;

		case (sf_state)
			INIT_STARS_SEED: begin
				sf_state_next = INIT_STARS;
			end

			INIT_STARS: begin
				sf_state_next = star_addr < STARS_COUNT - 1 ? INIT_STARS : INIT_STARS_DONE;
				star_addr_next = star_addr < STARS_COUNT - 1 ? star_addr + STARS_ADDRW'(1) : STARS_ADDRW'(0);
			end

			INIT_STARS_DONE: begin
				sf_state_next = LOAD_STAR_LOCS;
			end

			LOAD_STAR_LOCS: begin	
				sf_state_next = PROJECT_STAR_MUL;
			end
			PROJECT_STAR_MUL: begin	
				sf_state_next = PROJECT_STAR_DIV;
			end
			PROJECT_STAR_DIV: begin	
				sf_state_next = REPLACE_STAR;
			end
			REPLACE_STAR: begin	
				sf_state_next = STORE_STAR_DRAW;
			end
			STORE_STAR_DRAW: begin
				sf_state_next = star_addr < STARS_COUNT - 1 ? LOAD_STAR_LOCS : AWAIT_DRAW;
				star_addr_next = star_addr < STARS_COUNT - 1 ? star_addr + STARS_ADDRW'(1) : STARS_ADDRW'(0);
			end

			AWAIT_DRAW: begin
				sf_state_next = source_selected && write_awaited ? DRAW_STARS : AWAIT_DRAW;
			end

			DRAW_STARS: begin
				sf_state_next = star_addr < STARS_COUNT ? DRAW_STARS : LOAD_STAR_LOCS;
				star_addr_next = star_addr < STARS_COUNT ? star_addr + STARS_ADDRW'(1) : STARS_ADDRW'(0);
			end

			default begin
				sf_state_next = sf_state;
				star_addr_next = star_addr;
			end
		endcase
	end

	// update starfield state
	always_ff @(posedge clk) begin
		if (~resetN) begin
			sf_state <= INIT_STARS_SEED;
			star_addr <= 0;
		end else begin
			sf_state <= sf_state_next;
			star_addr <= star_addr_next;
		end
	end

	// For each star - which screen x,y to draw on?
	// Create a buffer until draw state (pipeline the projections)
	// (Stars Count) X (x or y) X (32 bit coordinate)
	// Signed so we can have out of bound stars - add another bit we have the positive
	// range cover the entire needed draw size
	logic signed [DRAW_WIDTH_ADDRW:0] stars_draw_buffer_x [0:STARS_COUNT-1];
	logic signed [DRAW_HEIGHT_ADDRW:0] stars_draw_buffer_y [0:STARS_COUNT-1];
	logic [2:0] stars_draw_buffer_c [0:STARS_COUNT-1];

	wire draw_outbound_star_x_neg = stars_draw_t_x < 0;
	wire draw_outbound_star_x_pos = stars_draw_t_x >= DRAW_WIDTH;
	wire draw_outbound_star_y_neg = stars_draw_t_y < 0;
	wire draw_outbound_star_y_pos = stars_draw_t_y >= DRAW_HEIGHT;

	wire star_out_of_draw_range = 
		draw_outbound_star_x_neg ||
		draw_outbound_star_x_pos ||
		draw_outbound_star_y_neg ||
		draw_outbound_star_y_pos;
	
	wire space_outbound_star_x_neg = star_loc_t_x < -SPACE_WIDTH_OFF_LIMIT;
	wire space_outbound_star_x_pos = star_loc_t_x > SPACE_WIDTH_OFF_LIMIT;
	wire space_outbound_star_y_neg = star_loc_t_y < -SPACE_HEIGHT_OFF_LIMIT;
	wire space_outbound_star_y_pos = star_loc_t_y > SPACE_HEIGHT_OFF_LIMIT;
	
	wire space_outbound_star_z_neg = star_loc_t_z <= STARS_Z_SPEED;

	// Draw Starfield onto Active framebuffer
	always_ff @ (posedge clk) begin
		if (~resetN) begin
			lfsr_reset <= 0;
			lfsr_en <= 0;
		end else begin
			case (sf_state)
				INIT_STARS_SEED: begin
					lfsr_reset <= 1;
					lfsr_en <= 1;
				end

				INIT_STARS: begin
					lfsr_reset <= 0;
					// Initialize curr star with 3d loc
					star_locs_x[star_addr] <= lfsr_x; // x
					star_locs_y[star_addr] <=  lfsr_y; // y
					star_locs_z[star_addr] <=  lfsr_z % SPACE_DEPTH; // z
				end

				INIT_STARS_DONE: begin
					lfsr_en <= 0;
				end

				LOAD_STAR_LOCS: begin
					star_loc_t_x <= star_locs_x[star_addr];
					star_loc_t_y <= star_locs_y[star_addr];
					star_loc_t_z <= star_locs_z[star_addr];
				end

				PROJECT_STAR_MUL: begin
					if (star_loc_t_x >= 0) begin
						loc_mul_res_t_x <= star_loc_t_x * FOCAL_LENGTH;
					end else begin
						loc_mul_res_t_x <= (0 - star_loc_t_x) * FOCAL_LENGTH;
					end

					if (star_loc_t_y >= 0) begin
						loc_mul_res_t_y <= star_loc_t_y * FOCAL_LENGTH;
					end else begin
						loc_mul_res_t_y <= (0 - star_loc_t_y) * FOCAL_LENGTH;
					end

					stars_draw_t_c <= star_loc_t_z < SPACE_DEPTH / 2 ? 3'b111 :
														star_loc_t_z < SPACE_DEPTH * 2 / 3 ? 3'b110 :
														3'b100;
				end

				PROJECT_STAR_DIV: begin
					if (star_loc_t_x >= 0) begin
						stars_draw_t_x <= DRAW_WIDTH_HALF + loc_mul_res_t_x / star_loc_t_z;
					end else begin
						stars_draw_t_x <= DRAW_WIDTH_HALF - loc_mul_res_t_x / star_loc_t_z;
					end

					if (star_loc_t_y >= 0) begin
						stars_draw_t_y <= DRAW_WIDTH_HALF + loc_mul_res_t_y / star_loc_t_z;
					end else begin
						stars_draw_t_y <= DRAW_WIDTH_HALF - loc_mul_res_t_y / star_loc_t_z;
					end

					lfsr_en <= 1;
				end

				REPLACE_STAR: begin
					if (space_outbound_star_x_neg || space_outbound_star_x_pos) begin
						star_loc_t_x <= lfsr_x;
					end else if (space_outbound_star_y_neg || space_outbound_star_y_pos) begin
						star_loc_t_y <= lfsr_y;
					end else begin
						star_loc_t_x <= tilt_direction_x ? star_loc_t_x + tilt_amount_x * STARS_X_SPEED : star_loc_t_x - tilt_amount_x * STARS_X_SPEED;
						star_loc_t_y <= tilt_direction_y ? star_loc_t_y + tilt_amount_y * STARS_Y_SPEED : star_loc_t_y - tilt_amount_y * STARS_Y_SPEED;
					end
					
					if (space_outbound_star_z_neg || star_out_of_draw_range) begin
						star_loc_t_z <= SPACE_DEPTH - lfsr_z % (SPACE_DEPTH / 3);
						star_loc_t_x <= lfsr_x;
						star_loc_t_y <= lfsr_y;
					end else begin
						star_loc_t_z <= star_loc_t_z - STARS_Z_SPEED;
					end
				end

				STORE_STAR_DRAW: begin
					lfsr_en <= 0;
					stars_draw_buffer_x[star_addr] <= stars_draw_t_x;
					stars_draw_buffer_y[star_addr] <= stars_draw_t_y;
					stars_draw_buffer_c[star_addr] <= stars_draw_t_c;
					star_locs_x[star_addr] <= star_loc_t_x;
					star_locs_y[star_addr] <= star_loc_t_y;
					star_locs_z[star_addr] <= star_loc_t_z;
				end

				AWAIT_DRAW, DRAW_STARS: begin
					stars_draw_t_x <= stars_draw_buffer_x[star_addr];
					stars_draw_t_y <= stars_draw_buffer_y[star_addr];
					star_draw_color_t <= {stars_draw_buffer_c[star_addr], stars_draw_buffer_c[star_addr], stars_draw_buffer_c[star_addr]};
				end

				default: ;
			endcase
		end
	end

	wire write_active_int = sf_state == DRAW_STARS;
	wire [COLOR_DEPTH-1:0] write_color_data_int = star_draw_color_t;
	wire [DRAW_WIDTH_ADDRW-1:0] write_x_addr_int = stars_draw_t_x;
	wire [DRAW_HEIGHT_ADDRW-1:0] write_y_addr_int = stars_draw_t_y;
	wire write_transparent_int = star_out_of_draw_range ? 1'b1 : 1'b0;

	
	assign write_active = source_selected ? write_active_int : 'z;
	assign write_color_data = source_selected ? write_color_data_int : 'z;
	assign write_x_addr = source_selected ? write_x_addr_int : 'z;
	assign write_y_addr = source_selected ? write_y_addr_int : 'z;
	assign write_transparent = source_selected ? write_transparent_int : 'z;

endmodule