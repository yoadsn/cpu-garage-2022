module Bkg_draw #(
  parameter BKG_COLOR = 8'b010010010,
  parameter SOURCE_ID = 0,
  parameter COLOR_DEPTH = 9
)(
	input						clk,
	input						resetN,
	input		[SOURCE_SEL_ADDRW-1:0]  	write_source_sel,
	input		    write_awaited,
	output      write_active,
	output	[COLOR_DEPTH-1:0]  write_color_data,
	output	[31:0]  write_x_addr,
	output	[31:0]  write_y_addr
	);

`include "frame_manager.h"

parameter DRAW_WIDTH = 640;
parameter DRAW_HEIGHT = 480;

enum {
  AWAIT_WRITE,
  ACTIVATE_WRITE,
  WRITE_ACTIVE,
  WRITE_DONE
} draw_state, draw_state_next;
always_comb begin
  draw_state_next = AWAIT_WRITE;

  case (draw_state)
    AWAIT_WRITE: begin
      draw_state_next = write_awaited && write_source_sel == SOURCE_ID ? ACTIVATE_WRITE : AWAIT_WRITE;
    end
    ACTIVATE_WRITE: begin
      draw_state_next = WRITE_ACTIVE;
    end
    WRITE_ACTIVE: begin
      draw_state_next = column == DRAW_WIDTH - 1 && row == DRAW_HEIGHT - 1 ? WRITE_DONE : WRITE_ACTIVE;
    end
    WRITE_DONE: begin
      draw_state_next = AWAIT_WRITE;
    end
  endcase

  if (~resetN) begin
    draw_state_next = AWAIT_WRITE;
  end
end

always_ff @ (posedge clk) begin
  draw_state <= draw_state_next;
end

logic [31:0] column, row;
logic [11:0] draw_color;
always_ff @ (posedge clk or negedge resetN) begin
  if (~resetN) begin
    column <= 0;
    row <= 0;
    draw_color <= 0;
  end else begin
    case (draw_state)
      ACTIVATE_WRITE: begin
        column <= 0;
        row <= 0;
      end

      WRITE_ACTIVE: begin
        if (column == DRAW_WIDTH - 1) begin
          column <= 0;
          row <= row + 1;
        end else begin          
          column <= column + 1;
        end
        
        draw_color <= BKG_COLOR;
      end
    endcase
  end
end

assign write_active = write_source_sel == SOURCE_ID ? (draw_state == WRITE_ACTIVE) : 'z;
assign write_color_data = write_source_sel == SOURCE_ID ? draw_color : 'z;
assign write_x_addr = write_source_sel == SOURCE_ID && column < DRAW_WIDTH ? column : 'z;
assign write_y_addr = write_source_sel == SOURCE_ID && row < DRAW_HEIGHT ? row : 'z;

endmodule