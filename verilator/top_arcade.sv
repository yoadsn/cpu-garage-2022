`default_nettype none
`timescale 1ns / 1ps

// Designer: Mor (Mordechai) Dahan, Avi Salmon,
// Sep. 2022
// ***********************************************

//`define ENABLE_ADC_CLOCK
//`define ENABLE_CLOCK1
//`define ENABLE_CLOCK2
//`define ENABLE_SDRAM
/* `define ENABLE_HEX0
`define ENABLE_HEX1
`define ENABLE_HEX2
`define ENABLE_HEX3
`define ENABLE_HEX4
`define ENABLE_HEX5 */
//`define ENABLE_KEY
//`define ENABLE_LED
`define ENABLE_SW
`define ENABLE_VGA
//`define ENABLE_ACCELEROMETER
//`define ENABLE_ARDUINO
//`define ENABLE_GPIO

module Top_template(

	//////////// ADC CLOCK: 3.3-V LVTTL //////////
`ifdef ENABLE_ADC_CLOCK
	input 		          		ADC_CLK_10,
`endif
	//////////// CLOCK 1: 3.3-V LVTTL //////////
`ifdef ENABLE_CLOCK1
	input 		          		MAX10_CLK1_50,
`endif
	//////////// CLOCK 2: 3.3-V LVTTL //////////
`ifdef ENABLE_CLOCK2
	input 		          		MAX10_CLK2_50,
`endif

	//////////// SDRAM: 3.3-V LVTTL //////////
`ifdef ENABLE_SDRAM
	output		    [12:0]		DRAM_ADDR,
	output		     [1:0]		DRAM_BA,
	output		          		DRAM_CAS_N,
	output		          		DRAM_CKE,
	output		          		DRAM_CLK,
	output		          		DRAM_CS_N,
	inout 		    [15:0]		DRAM_DQ,
	output		          		DRAM_LDQM,
	output		          		DRAM_RAS_N,
	output		          		DRAM_UDQM,
	output		          		DRAM_WE_N,
`endif

	//////////// SEG7: 3.3-V LVTTL //////////
`ifdef ENABLE_HEX0
	output		     [7:0]		HEX0,
`endif
`ifdef ENABLE_HEX1
	output		     [7:0]		HEX1,
`endif
`ifdef ENABLE_HEX2
	output		     [7:0]		HEX2,
`endif
`ifdef ENABLE_HEX3
	output		     [7:0]		HEX3,
`endif
`ifdef ENABLE_HEX4
	output		     [7:0]		HEX4,
`endif
`ifdef ENABLE_HEX5
	output		     [7:0]		HEX5,
`endif

	//////////// KEY: 3.3 V SCHMITT TRIGGER //////////
`ifdef ENABLE_KEY
	input 		     [1:0]		KEY,
`endif

	//////////// LED: 3.3-V LVTTL //////////
`ifdef ENABLE_LED
	output		     [9:0]		LEDR,
`endif

	//////////// SW: 3.3-V LVTTL //////////
`ifdef ENABLE_SW
	input 		     [9:0]		SW,
`endif

	//////////// VGA: 3.3-V LVTTL //////////
`ifdef ENABLE_VGA
	output		     [3:0]		VGA_B,
	output		     [3:0]		VGA_G,
	output		          		VGA_HS,
	output		     [3:0]		VGA_R,
	output		          		VGA_VS,
`endif

	//////////// Accelerometer: 3.3-V LVTTL //////////
`ifdef ENABLE_ACCELEROMETER
	output		          		GSENSOR_CS_N,
	input 		     [2:1]		GSENSOR_INT,
	output		          		GSENSOR_SCLK,
	inout 		          		GSENSOR_SDI,
	inout 		          		GSENSOR_SDO,
`endif

	//////////// Arduino: 3.3-V LVTTL //////////
`ifdef ENABLE_ARDUINO
	output 		    [15:0]		ARDUINO_IO,
	inout 		          		ARDUINO_RESET_N,
`endif

	//////////// GPIO, GPIO connect to GPIO Default: 3.3-V LVTTL //////////
`ifdef ENABLE_GPIO
	inout 		    [35:0]		GPIO,
`endif

	/// Verilator adaptation
	output logic [31:0] pxl_x,
	output logic [31:0] pxl_y,
	output disp_ena,
	input clk_25,
	input clk_50,
	input clk_100,

	// Adaptation of the inputs controles
	input	A,
	input	B,
	input	Select,
	input	Start,
	input	Right,
	input	Left,
	input	Up,
	input	Down,
	input [11:0]	Wheel,
	
	// Emulates the Gsensor
	input [9:0] 	TiltX,
	input [9:0] 	TiltY
);

localparam COLOR_DEPTH = 9;
localparam COLOR_CH_WIDTH = COLOR_DEPTH / 3;

//=======================================================
//  REG/WIRE declarations
//=======================================================

// clock signals
/* wire				clk_25;
wire				clk_50;
wire				clk_100; */

// Screens signals
//wire	[31:0]	pxl_x;
//wire	[31:0]	pxl_y;
wire				frame;
wire				h_sync_wire;
wire				v_sync_wire;
wire	[3:0]		vga_r_wire;
wire	[3:0]		vga_g_wire;
wire	[3:0]		vga_b_wire;
wire	[7:0]		lcd_db;
wire				lcd_reset;
wire				lcd_wr;
wire				lcd_d_c;
wire				lcd_rd;
wire				lcd_buzzer;
wire				lcd_status_led;
wire	[COLOR_CH_WIDTH-1:0]		Red_level;
wire	[COLOR_CH_WIDTH-1:0]		Green_level;
wire	[COLOR_CH_WIDTH-1:0]		Blue_level;

// Periphery signals
/* wire	A;
wire	B;
wire	Select;
wire	Start;
wire	Right;
wire	Left;
wire	Up;
wire	Down;
wire [11:0]	Wheel; */


// Screens Assigns
//assign ARDUINO_IO[7:0]	= lcd_db;
//assign ARDUINO_IO[8] 	= lcd_reset;
//assign ARDUINO_IO[9]		= lcd_wr;
//assign ARDUINO_IO[10]	= lcd_d_c;
//assign ARDUINO_IO[11]	= lcd_rd;
//assign ARDUINO_IO[12]	= lcd_buzzer;
//assign ARDUINO_IO[13]	= lcd_status_led;
assign VGA_HS = h_sync_wire;
assign VGA_VS = v_sync_wire;
assign VGA_R = vga_r_wire;
assign VGA_G = vga_g_wire;
assign VGA_B = vga_b_wire;


// Screens control (LCD and VGA)
Screens_dispaly #(
	.COLOR_DEPTH(COLOR_DEPTH)
) Screen_control(
	.clk_25(clk_25),
	.clk_100(clk_100),
	.Red_level(Red_level),
	.Green_level(Green_level),
	.Blue_level(Blue_level),
	.pxl_x(pxl_x),
	.pxl_y(pxl_y),
	.frame,
	.Red(vga_r_wire),
	.Green(vga_g_wire),
	.Blue(vga_b_wire),
	.h_sync(h_sync_wire),
	.v_sync(v_sync_wire),
	.lcd_db(lcd_db),
	.lcd_reset(lcd_reset),
	.lcd_wr(lcd_wr),
	.lcd_d_c(lcd_d_c),
	.lcd_rd(lcd_rd),
	.disp_ena(disp_ena)
);


// Utilities

// 25M clk generation
/* pll25	pll25_inst (
	.areset ( 1'b0 ),
	.inclk0 ( MAX10_CLK1_50 ),
	.c0 ( clk_25 ),
	.c1 ( clk_50 ),
	.c2 ( clk_100 ),
	.locked ( )
	); */


//7-Seg default assign (all leds are off)
/* assign HEX0 = 8'b11111111;
assign HEX1 = 8'b11111111;
assign HEX2 = 8'b11111111;
assign HEX3 = 8'b11111111; */

// periphery_control module for external units: joystick, wheel and buttons (A,B, Select and Start) 
/* periphery_control periphery_control_inst(
	.clk(clk_25),
	.A(A),
	.B(B),
	.Select(Select),
	.Start(Start),
	.Right(Right),
	.Left(Left),
	.Up(Up),
	.Down(Down),
	.Wheel(Wheel)
	); */
	
	// Leds and 7-Seg show periphery_control outputs
	//assign LEDR[0] = A; 			// A
	//assign LEDR[1] = B; 			// B
	//assign LEDR[2] = Select;	// Select
	//assign LEDR[3] = Start; 	// Start
	//assign LEDR[9] = Left; 		// Left
	//assign LEDR[8] = Right; 	// Right
	//assign LEDR[7] = Up; 		// UP
	//assign LEDR[6] = Down; 		// DOWN

/* seven_segment ss5(
	.in_hex(Wheel[11:8]),
	.out_to_ss(HEX5)
);

seven_segment ss4(
	.in_hex(Wheel[7:4]),
	.out_to_ss(HEX4)
); */

wire [3:0] tilt_amount_x;
wire tilt_direction_x;
Gsensemu_pars gsens_pars_x	(	
						.iDIG(TiltX),
						.iG_INT2(1),
						.tilt_amount(tilt_amount_x),
						.tilt_direction(tilt_direction_x)
						);

wire [3:0] tilt_amount_y;
wire tilt_direction_y;
/* Gsensemu_pars gsens_pars_y	(	
						.iDIG(TiltY),
						.iG_INT2(1),
						.tilt_amount(tilt_amount_y),
						.tilt_direction(tilt_direction_y)
						); */

wire [COLOR_DEPTH-1:0] bf_draw_data;
wire [31:0] bf_x_write_addr, bf_y_write_addr;
wire bf_write_active, bf_write_awaited, bf_write_source_sel, bf_write_transparent;
Frame_manager #(
	.MAX_WRITE_SOURCE(1),
	.COLOR_DEPTH(COLOR_DEPTH)
) fb_mgr (
	.clk(clk_25),
	.resetN(~A),
	.frame,
	.write_color_data(bf_draw_data),
	.write_transparent(bf_write_transparent),
	.write_x_addr(bf_x_write_addr),
	.write_y_addr(bf_y_write_addr),
	.write_active(bf_write_active),
	.write_awaited(bf_write_awaited),
	.write_source_sel(bf_write_source_sel),

	.read_x_addr(pxl_x),
	.read_y_addr(pxl_y),
	.read_color_data({ Red_level, Green_level, Blue_level })
);


Bkg_draw #(
	.BKG_COLOR(9'b000000000),
	.SOURCE_ID(0),
	.COLOR_DEPTH(COLOR_DEPTH)
) bkg(
	.clk(clk_25),
	.resetN(~A),
	.write_color_data(bf_draw_data),
	.write_x_addr(bf_x_write_addr),
	.write_y_addr(bf_y_write_addr),
	.write_active(bf_write_active),
	.write_awaited(bf_write_awaited),
	.write_source_sel(bf_write_source_sel)
);


Starfield_unit	#(
	.SOURCE_ID(1),
	.COLOR_DEPTH(COLOR_DEPTH)
) Starfield_unit_inst(
	.clk(clk_25),
	.resetN(~A),
	.frame(frame),
	.SW,

	.write_color_data(bf_draw_data),
	.write_transparent(bf_write_transparent),
	.write_x_addr(bf_x_write_addr),
	.write_y_addr(bf_y_write_addr),
	.write_active(bf_write_active),
	.write_awaited(bf_write_awaited),
	.write_source_sel(bf_write_source_sel),

	.tilt_amount_x,
	.tilt_direction_x,
	.tilt_amount_y,
	.tilt_direction_y
);

/*
Gsenscal_draw #(
	.SOURCE_ID(0),
	.COLOR_DEPTH(COLOR_DEPTH),
	.TILE_SCALE_FACTOR(3)
) bkg(
	.clk(clk_25),
	.resetN(~A),
	.tilt_amount_x,
	.tilt_direction_x,
	.tilt_amount_y,
	.tilt_direction_y,
	.write_color_data(bf_draw_data),
	.write_x_addr(bf_x_write_addr),
	.write_y_addr(bf_y_write_addr),
	.write_active(bf_write_active),
	.write_awaited(bf_write_awaited),
	.write_source_sel(bf_write_source_sel)
);*/

endmodule
