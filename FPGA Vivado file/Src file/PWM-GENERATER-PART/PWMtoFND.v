`timescale 1ns / 1ps

module PWMtoFND(
    input [1:0] i_pwm_duty,
    output [13:0] o_pwm_to_fnd
    );
    reg [11:0] r_zero = 0;
    assign o_pwm_to_fnd = {r_zero[11:0], i_pwm_duty[1:0]};
    
endmodule
