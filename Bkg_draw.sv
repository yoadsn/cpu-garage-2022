module Bkg_draw #(
  parameter BKG_COLOR = 8'b010010010,
  parameter SOURCE_ID = SOURCE_SEL_ADDRW'(0)
)(
	input						clk,
	input						resetN,
	input		[SOURCE_SEL_ADDRW-1:0]  	write_source_sel,
	input		    write_awaited,
	output      write_active,
	output	[COLOR_DEPTH-1:0]  write_color_data,
  output		write_transparent,
	output	[DRAW_WIDTH_ADDRW-1:0]	write_x_addr,
	output	[DRAW_HEIGHT_ADDRW-1:0]	write_y_addr
	);

`include "frame_manager.h"

typedef enum logic [1:0] {
  AWAIT_WRITE,
  ACTIVATE_WRITE,
  WRITE_ACTIVE,
  WRITE_DONE
} stateType;
stateType draw_state, draw_state_next;
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
      draw_state_next = column == LAST_COL && row == LAST_ROW ? WRITE_DONE : WRITE_ACTIVE;
    end
    WRITE_DONE: begin
      draw_state_next = AWAIT_WRITE;
    end
  endcase
end

always_ff @ (posedge clk or negedge resetN) begin
	if (~resetN) draw_state <= AWAIT_WRITE;
   else draw_state <= draw_state_next;
end

logic [DRAW_WIDTH_ADDRW-1:0] column;
logic [DRAW_HEIGHT_ADDRW-1:0] row;
always_ff @ (posedge clk or negedge resetN) begin
  if (~resetN) begin
    column <= FIRST_COL;
    row <= FIRST_ROW;
  end else begin
    case (draw_state)
      ACTIVATE_WRITE: begin
        column <= FIRST_COL;
        row <= FIRST_COL;
      end

      WRITE_ACTIVE: begin
        if (column == LAST_COL) begin
          column <= FIRST_COL;
          row <= row + 1;
        end else begin          
          column <= column + 1;
        end
      end
    endcase
  end
end

assign write_active = write_source_sel == SOURCE_ID ? (draw_state == WRITE_ACTIVE) : 'z;
assign write_color_data = write_source_sel == SOURCE_ID ? BKG_COLOR : 'z;
assign write_x_addr = write_source_sel == SOURCE_ID && column < DRAW_WIDTH ? column : 'z;
assign write_y_addr = write_source_sel == SOURCE_ID && row < DRAW_HEIGHT ? row : 'z;
assign write_transparent = write_source_sel == SOURCE_ID ? 1'b0 : 'z;

endmodule