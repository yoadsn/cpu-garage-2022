localparam	SOURCE_SEL_ADDRW			  =	2;

localparam  DRAW_WIDTH = 11'd640;
localparam  DRAW_HEIGHT = 10'd480;
localparam  DRAW_WIDTH_ADDRW = $clog2(DRAW_WIDTH);
localparam  DRAW_HEIGHT_ADDRW = $clog2(DRAW_HEIGHT);

localparam FIRST_COL = DRAW_WIDTH_ADDRW'(0);
localparam LAST_COL = DRAW_WIDTH - DRAW_WIDTH_ADDRW'(1);
localparam FIRST_ROW = DRAW_HEIGHT_ADDRW'(0);
localparam LAST_ROW = DRAW_HEIGHT - DRAW_HEIGHT_ADDRW'(1);

localparam COLOR_DEPTH = 9;