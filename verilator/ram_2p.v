`default_nettype none
`timescale 1ns / 1ps

module ram_2p #(
		parameter WIDTH = 12,
		parameter DEPTH = 640 * 480,
		parameter INIT_F = "",
		localparam ADDRW=$clog2(DEPTH)
) (
	input	[WIDTH-1:0]  data,
	input	[$clog2(DEPTH)-1:0]  rdaddress,
	input	rdclock,
	input	[18:0]  wraddress,
	input	wrclock,
	input	wren,
	output reg [WIDTH-1:0]  q
);

    logic [WIDTH-1:0] memory [DEPTH];

    initial begin
        if (INIT_F != 0) begin
            $display("Loading memory init file '%s' into bram_sdp.", INIT_F);
            $readmemh(INIT_F, memory);
        end
    end

    // Port A: Sync Write
    always_ff @(posedge wrclock) begin
        if (wren) memory[wraddress] <= data;
    end

    // Port B: Sync Read
    always_ff @(posedge rdclock) begin
        q <= memory[rdaddress];
    end
endmodule