module Gsensemu_pars (
	input		    [9:0]  iDIG,
	input		           iG_INT2,
	output			[3:0]  tilt_amount,
	output				   tilt_direction
);

logic				[9:0]  full_unsigned_amount;
logic				[4:0]  select_data;
logic				[3:0]  abs_select_high;

assign tilt_direction = iDIG[9]; // signed values
assign full_unsigned_amount = ~iDIG; // negative values are in 2's complement - reverse on full resolution bits

// 10bit resultion - take 4 MSB (excluding sign)
assign tilt_amount = tilt_direction ? full_unsigned_amount[8:5] : iDIG[8:5]; // neg numbers are 2s complement
endmodule