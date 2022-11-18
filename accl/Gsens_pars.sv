module Gsens_pars (
	input		    [9:0]  iDIG,
	input		           iG_INT2,
	output			[3:0]  tilt_amount,
	output				   tilt_direction
);

logic				[4:0]  select_data;
logic				[3:0]  abs_select_high;

assign select_data  = iG_INT2 ? iDIG[9:5] :  // +-2g resolution : 10-bit
                               (iDIG[9]?(iDIG[8]?iDIG[8:4]:5'h10):(iDIG[8]?5'hf:iDIG[8:4])); // +-g resolution : 9-bit                               
assign tilt_direction = select_data[4];
assign tilt_amount = tilt_direction ? (~select_data[3:0] + 1) : select_data[3:0]; // neg numbers are 2s complement
endmodule