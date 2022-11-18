module Gsenscal_draw #(
  parameter SOURCE_ID = 0,
  parameter COLOR_DEPTH = 9,
  parameter DRAW_WIDTH = 640,
  parameter DRAW_HEIGHT = 480,
  parameter TILE_SCALE_FACTOR = 1
)(
	input						clk,
	input						resetN,
	input		  	write_source_sel,
	input		    write_awaited,
	input		[3:0]	tilt_amount_x,
	input					tilt_direction_x,
	input		[3:0]	tilt_amount_y,
	input					tilt_direction_y,
	
  output      write_active,
	output	[COLOR_DEPTH-1:0]  write_color_data,
	output	[31:0]  write_x_addr,
	output	[31:0]  write_y_addr
	);

localparam DRAW_WIDTH_HALF = DRAW_WIDTH / 2;
localparam DRAW_HEIGHT_HALF = DRAW_HEIGHT / 2;
localparam MARK_SIZE = 10;

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


logic on_mark;
logic on_cross;
always_comb begin
  on_cross =
    (column >= DRAW_WIDTH_HALF - 1 && column <= DRAW_WIDTH_HALF) ||
    (row >= DRAW_HEIGHT_HALF - 1 && row <= DRAW_HEIGHT_HALF);
  on_mark =
    (column >= DRAW_WIDTH_HALF - 1 - MARK_SIZE + mark_x && column <= DRAW_WIDTH_HALF + MARK_SIZE + mark_x) &&
    (row >= DRAW_HEIGHT_HALF - 1 - MARK_SIZE + mark_y && row <= DRAW_HEIGHT_HALF + MARK_SIZE + mark_y);
end

shortint mark_x;
shortint mark_y;
always_ff @ (posedge clk or negedge resetN) begin
  if (~resetN) begin
    mark_x <= 0;
    mark_y <= 0;
  end else begin
    mark_x <= tilt_direction_x ? tilt_amount_x << TILE_SCALE_FACTOR : -(tilt_amount_x << TILE_SCALE_FACTOR);
	 mark_y <= tilt_direction_y ? tilt_amount_y << TILE_SCALE_FACTOR : -(tilt_amount_y << TILE_SCALE_FACTOR);
  end
end

shortint column, row;
logic [COLOR_DEPTH-1:0] draw_color;
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
        
        draw_color <= on_mark ?   9'h1c0 :
                      on_cross ?  9'h1ff :
                                  9'h000;
      end
    endcase
  end
end

assign write_active = write_source_sel == SOURCE_ID ? (draw_state == WRITE_ACTIVE) : 'z;
assign write_color_data = write_source_sel == SOURCE_ID ? draw_color : 'z;
assign write_x_addr = write_source_sel == SOURCE_ID && column < DRAW_WIDTH ? column : 'z;
assign write_y_addr = write_source_sel == SOURCE_ID && row < DRAW_HEIGHT ? row : 'z;

endmodule