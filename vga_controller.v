// VGA Sync machine
//
// 4/11/2021 Compiled from various sources

module vga_controller #(
   parameter h_pixels   = 640,   // horizontal display
   parameter h_fp       = 16,    // horizontal Front Porch
   parameter h_pulse    = 96,    // horizontal sync pulse
   parameter h_bp       = 48,    // horizontal back porch
   parameter h_pol      = 1'b0,  // horizontal sync polarity (1 = positive, 0 = negative)
   parameter v_pixels   = 480,   // vertical display
   parameter v_fp       = 10,    // vertical front porch
   parameter v_pulse    = 2,     // vertical pulse
   parameter v_bp       = 33,    // vertical back porch
   parameter v_pol      = 1'b0   // vertical sync polarity (1 = positive, 0 = negative)
)( input pixel_clk,           // Pixel clock
   input reset_n,             // Active low synchronous reset
   output reg h_sync,         // horizontal sync signal
   output reg v_sync,         // vertical sync signal
   output reg disp_ena,       // display enable (0 = all colors must be blank)
   output reg [31:0] draw_column,  // horizontal pixel coordinate
   output reg [31:0] draw_row,     // vertical pixel coordinate
   output reg [31:0] render_column,  // horizontal pixel coordinate
   output reg [31:0] render_row,     // vertical pixel coordinate
	output reg frame           // frame end signal
   );

   localparam DRAW_LAT = 1;

   // Get total number of row and column pixel clocks
   localparam h_period = h_pulse + h_bp + h_pixels + h_fp;
   localparam v_period = v_pulse + v_bp + v_pixels + v_fp;

   // Full range counters
   reg [$clog2(h_period)-1:0] h_count;
   reg [$clog2(v_period)-1:0] v_count;

   always @(posedge pixel_clk) begin
      // Perform reset operations if needed
      if (reset_n == 1'b0) begin
         h_count  <= 0;
         v_count  <= 0;
         h_sync   <= ~ h_pol;
         v_sync   <= ~ v_pol;
         disp_ena <= 1'b0;
         draw_column   <= 0;
         draw_row      <= 0;
         render_column   <= 0;
         render_row      <= 0;
      end else begin

         // Pixel Counters
         if (h_count < h_period - 1) begin
            h_count <= h_count + 1;
         end else begin
            h_count <= 0;
            if (v_count < v_period - 1) begin
               v_count <= v_count + 1;
            end else begin
               v_count <= 0;
            end
         end

         // Horizontal Sync Signal
         // moved by DRAW_LAT forward to shift incoming RGB by DRAW_LAT
         if ( (h_count < h_pixels + h_fp + DRAW_LAT) || (h_count > h_pixels + h_fp + h_pulse + DRAW_LAT) ) begin
            h_sync <= ~ h_pol;
         end else begin
            h_sync <= h_pol;
         end

         // Vertical Sync Signal
         if ( (v_count < v_pixels + v_fp) || (v_count > v_pixels + v_fp + v_pulse) ) begin
            v_sync <= ~ v_pol;
         end else begin
            v_sync <= v_pol;
         end

         // Update Pixel Coordinates
         if (h_count < h_pixels + DRAW_LAT) begin
            if (DRAW_LAT <= h_count) begin
               draw_column <= h_count - 1;
            end
            if (h_count < h_pixels) begin
               render_column <= h_count;
            end
         end

         if (v_count < v_pixels) begin
            draw_row <= v_count;
            render_row <= v_count;
         end
			
			if (h_count == h_pixels - 1 && v_count == v_pixels - 1) begin
            frame <= 1;
         end else begin
            frame <= 0;
         end

         // Set display enable output
         // Offset DRAW_LAT horizontally - enable drawing only when drawing X/Y in range
         if (DRAW_LAT <= h_count && h_count < h_pixels + DRAW_LAT && v_count < v_pixels) begin
            disp_ena <= 1'b1;
         end else begin
            disp_ena <= 1'b0;
         end
      end
   end

endmodule
