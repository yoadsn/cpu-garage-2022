// Designer: Mor (Mordechai) Dahan,
// Sep. 2022
// ***********************************************


module Draw_Ghost (
	
	input					clk,
	input					resetN,
	input		[31:0]	pxl_x,
	input		[31:0]	pxl_y,
	input		[31:0]	topLeft_x,
	input		[31:0]	topLeft_y,
	input		[31:0]	width,
	input		[31:0]	high,
	input					x_direction,
	output	[3:0]		Red_level,
	output	[3:0]		Green_level,
	output	[3:0]		Blue_level,
	output				Drawing
	
	);

wire	[31:0]	in_rectangle; 
wire	[31:0]	offset_x;
wire	[31:0]	offset_y;

logic[0:31][0:31][11:0] Bitmap = {
	{12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'hc00,12'hc00,12'hc00,12'hc00},
	{12'h888,12'h888,12'h888,12'hc88,12'h888,12'h888,12'hc88,12'hc88,12'hc88,12'h888,12'hc88,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'hc00,12'hc00,12'hc00,12'hc00},
	{12'h888,12'h888,12'h888,12'h888,12'hc88,12'hc88,12'h888,12'hc88,12'hc88,12'hc88,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'hc00,12'hc00,12'hc00,12'hc00},
	{12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h400,12'h400,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h400,12'h400,12'h400,12'h000,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h04c,12'h04c,12'h04c,12'h04c},
	{12'h888,12'h888,12'h888,12'h888,12'h888,12'h844,12'h400,12'h400,12'h400,12'h000,12'h888,12'h888,12'h888,12'h400,12'h400,12'h440,12'h000,12'h000,12'h000,12'h400,12'h400,12'h400,12'h400,12'h888,12'h888,12'h888,12'h888,12'h888,12'h04c,12'h04c,12'h04c,12'h04c},
	{12'h888,12'h888,12'h888,12'h888,12'h400,12'h400,12'h400,12'h400,12'h400,12'h000,12'h400,12'h400,12'h400,12'hc88,12'hc88,12'h400,12'h400,12'h400,12'h888,12'h400,12'h400,12'h400,12'h400,12'h400,12'h888,12'h888,12'h888,12'h888,12'h04c,12'h04c,12'h04c,12'h04c},
	{12'h888,12'h888,12'h888,12'h400,12'h400,12'h400,12'h400,12'h400,12'h000,12'h400,12'h400,12'h400,12'hc88,12'hc88,12'hc88,12'hc88,12'h400,12'h400,12'h400,12'h888,12'h400,12'h400,12'h400,12'h400,12'h400,12'h888,12'h888,12'h448,12'h084,12'h084,12'h084,12'h084},
	{12'h888,12'h888,12'h400,12'h400,12'h400,12'h400,12'h400,12'h400,12'h888,12'h400,12'h400,12'h400,12'hc88,12'hc88,12'hc88,12'hc88,12'h400,12'h400,12'h400,12'h400,12'h400,12'h400,12'h400,12'h400,12'h400,12'h400,12'h888,12'h888,12'h084,12'h084,12'h084,12'h084},
	{12'h888,12'h888,12'h000,12'h400,12'h400,12'h400,12'h400,12'h400,12'h888,12'h400,12'hc88,12'hc88,12'h000,12'hc88,12'hc88,12'hc88,12'h400,12'hc88,12'h000,12'h400,12'h888,12'h400,12'h400,12'h400,12'h400,12'h444,12'h888,12'h888,12'h084,12'h084,12'h084,12'h084},
	{12'h888,12'h888,12'h888,12'h888,12'h400,12'h400,12'h888,12'h888,12'h888,12'h400,12'h000,12'h000,12'h400,12'hc88,12'hc88,12'hc88,12'h000,12'h000,12'h400,12'h400,12'h888,12'h888,12'h400,12'h400,12'h888,12'h888,12'h888,12'h888,12'h084,12'h084,12'h084,12'h084},
	{12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h844,12'h400,12'h400,12'h400,12'h400,12'h400,12'hc88,12'h000,12'h400,12'h400,12'h400,12'h400,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888},
	{12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h400,12'h400,12'hc88,12'hc88,12'hc88,12'hc88,12'hc88,12'hc88,12'hc88,12'h888,12'h844,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h444,12'h444},
	{12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'hc88,12'hc88,12'hc88,12'h888,12'h444,12'h000,12'hc88,12'hc88,12'hc88,12'hc88,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h444,12'h448,12'h448,12'h444},
	{12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h844,12'hc88,12'hc88,12'hc88,12'hc88,12'h000,12'h000,12'h000,12'hc88,12'hc88,12'hc88,12'hc88,12'h000,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h444,12'h448,12'h444},
	{12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'hc88,12'hc88,12'hc88,12'hc88,12'h888,12'h000,12'hc88,12'hc88,12'hc88,12'h884,12'hc88,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h444,12'h444,12'h444,12'h444},
	{12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h440,12'hc88,12'h000,12'h800,12'h800,12'h800,12'h000,12'h000,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h884,12'h884,12'h884,12'h884,12'h444},
	{12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h884,12'h888,12'h400,12'h000,12'h400,12'h400,12'h400,12'h800,12'h800,12'h800,12'h400,12'h888,12'h888,12'h888,12'h888,12'h888,12'h884,12'h884,12'h888,12'h884,12'h884,12'h888,12'h884,12'h444},
	{12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h400,12'h400,12'h400,12'h888,12'h888,12'h000,12'h888,12'h000,12'h400,12'h400,12'h400,12'h888,12'h888,12'h888,12'h888,12'h000,12'h444,12'h884,12'h884,12'h884,12'h884,12'h444,12'h444},
	{12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h000,12'h400,12'h400,12'h400,12'h888,12'hc88,12'h880,12'hc88,12'h888,12'h400,12'h400,12'h400,12'h000,12'h888,12'h888,12'h884,12'h400,12'h884,12'h888,12'h888,12'h884,12'h884,12'h844,12'h444},
	{12'h444,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h400,12'h400,12'h400,12'h888,12'h888,12'h880,12'h840,12'hc80,12'h888,12'h400,12'h400,12'h400,12'h400,12'h888,12'h000,12'h400,12'h400,12'h884,12'h884,12'h888,12'h888,12'h884,12'h844,12'h444},
	{12'h884,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h400,12'h400,12'h400,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h400,12'h400,12'h400,12'h400,12'h888,12'h888,12'h888,12'h000,12'h884,12'h888,12'h884,12'h884,12'h884,12'h884,12'h884},
	{12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h000,12'h000,12'h400,12'h400,12'h400,12'h400,12'h888,12'h888,12'h888,12'h888,12'h888,12'h400,12'h400,12'h400,12'h400,12'h000,12'h000,12'h884,12'h884,12'h884,12'h444,12'h888,12'h884,12'h844,12'h884,12'h884},
	{12'h888,12'h888,12'h884,12'h888,12'h888,12'h000,12'h000,12'h000,12'h400,12'h400,12'h400,12'h400,12'h888,12'h888,12'h888,12'h888,12'h888,12'h400,12'h400,12'h400,12'h400,12'h000,12'h000,12'h000,12'h884,12'h884,12'h884,12'h884,12'h884,12'h444,12'h444,12'h444},
	{12'h884,12'h884,12'h884,12'h884,12'h884,12'h000,12'h000,12'h000,12'h000,12'h400,12'h400,12'h400,12'h400,12'h888,12'h888,12'h888,12'h000,12'h400,12'h400,12'h400,12'h400,12'h000,12'h000,12'h000,12'h444,12'h884,12'h884,12'h884,12'h884,12'h884,12'h884,12'h444},
	{12'h884,12'h884,12'h888,12'h884,12'h888,12'h000,12'h000,12'h000,12'h000,12'h400,12'h400,12'h400,12'h400,12'h888,12'h888,12'h888,12'h400,12'h400,12'h400,12'h400,12'h000,12'h000,12'h000,12'h000,12'h484,12'h884,12'h444,12'h444,12'h444,12'h444,12'h444,12'h444},
	{12'h884,12'h884,12'h888,12'h884,12'h444,12'h884,12'h000,12'h000,12'h000,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h888,12'h000,12'h400,12'h400,12'h000,12'h000,12'h000,12'h000,12'h400,12'h884,12'h444,12'h444,12'h444,12'h000,12'h000,12'h444,12'h444},
	{12'h444,12'h444,12'h000,12'h444,12'h484,12'h000,12'h884,12'h000,12'h888,12'h888,12'h888,12'h880,12'h888,12'h888,12'h884,12'h888,12'h888,12'h884,12'h888,12'h884,12'h400,12'h000,12'h000,12'h884,12'h884,12'h444,12'h444,12'h444,12'h040,12'h444,12'h444,12'h484},
	{12'h444,12'h440,12'h000,12'h000,12'h888,12'h440,12'h884,12'h888,12'h884,12'h888,12'h888,12'h880,12'h440,12'h000,12'h884,12'h480,12'h440,12'h884,12'h884,12'h884,12'h884,12'h000,12'h884,12'h884,12'h000,12'h444,12'h444,12'h440,12'h040,12'h444,12'h444,12'h444},
	{12'h440,12'h484,12'h000,12'h000,12'h440,12'h444,12'h884,12'h884,12'h440,12'h888,12'h884,12'h440,12'h000,12'h440,12'h440,12'h040,12'h000,12'h888,12'h440,12'h888,12'h884,12'h884,12'h884,12'h040,12'h040,12'h888,12'h484,12'h000,12'h040,12'h440,12'h040,12'h440},
	{12'h040,12'h040,12'h000,12'h040,12'h040,12'h040,12'h000,12'h884,12'h480,12'h484,12'h040,12'h000,12'h040,12'h000,12'h040,12'h040,12'h000,12'h040,12'h040,12'h884,12'h000,12'h440,12'h884,12'h000,12'h000,12'h040,12'h444,12'h040,12'h040,12'h040,12'h000,12'h440},
	{12'h040,12'h040,12'h040,12'h000,12'h040,12'h040,12'h040,12'h040,12'h440,12'h040,12'h444,12'h440,12'h040,12'h040,12'h040,12'h000,12'h040,12'h040,12'h040,12'h040,12'h000,12'h040,12'h040,12'h040,12'h040,12'h000,12'h040,12'h040,12'h040,12'h040,12'h040,12'h040},
	{12'h040,12'h040,12'h000,12'h000,12'h040,12'h040,12'h000,12'h040,12'h040,12'h040,12'h040,12'h040,12'h040,12'h040,12'h040,12'h040,12'h040,12'h040,12'h040,12'h040,12'h040,12'h040,12'h040,12'h040,12'h000,12'h040,12'h000,12'h040,12'h040,12'h440,12'h040,12'h040}};


	
	assign in_rectangle = (pxl_x >= topLeft_x) && (pxl_x <= topLeft_x+width) && (pxl_y >= topLeft_y) && (pxl_y <= topLeft_y+high);
assign offset_x = pxl_x - topLeft_x;
assign offset_y = pxl_y - topLeft_y;

localparam TANSPERENT = 12'hFFF;

always @(posedge clk or negedge resetN) begin
	if (!resetN) begin
		Drawing <= 0;
		Red_level <= 4'hF;
		Green_level <= 4'hF;
		Blue_level <= 4'hF;
	end
	else begin
		Drawing <= 0;
		if (in_rectangle) begin
			if(!x_direction) begin
				if(Bitmap[offset_y][offset_x] != TANSPERENT) begin
					Drawing <= 1;
					Red_level <= Bitmap[offset_y][offset_x] [11:8];
					Green_level <= Bitmap[offset_y][offset_x] [7:4];
					Blue_level <= Bitmap[offset_y][offset_x] [3:0];
				end
			end
			else begin
				if(Bitmap[offset_y][width-offset_x+1] != TANSPERENT) begin
					Drawing <= 1;
					Red_level <= Bitmap[offset_y][width-offset_x+1] [11:8];
					Green_level <= Bitmap[offset_y][width-offset_x+1] [7:4];
					Blue_level <= Bitmap[offset_y][width-offset_x+1] [3:0];
				end
			end
		end
	end
end

endmodule