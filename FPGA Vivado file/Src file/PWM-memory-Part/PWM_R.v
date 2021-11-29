`timescale 1ns / 1ps

module PWM_R(
    input i_addr,
    input i_cs,
    input [7:0]i_pwm_value,
    input i_clk,
    output [15:0] o_pwm_reg
    );
    reg [7:0] r_pwm_reg[0:1];
    assign o_pwm_reg = {r_pwm_reg[1],r_pwm_reg[0]};
    
    always @(posedge i_clk) begin
        if(i_cs ==0 ) begin 
        case(i_addr)
            0: r_pwm_reg[0] <= i_pwm_value;
            1: r_pwm_reg[1] <= i_pwm_value;
        endcase
      end
    end
    
endmodule
