`timescale 1ns / 1ps

module PWM_MEM_Gen(
    input sysclk,
    input i_en,
    input i_addr,
    input i_cs,
    input [7:0] i_pwm_value,
    input i_clk,
    output o_pwm_clk
    );
    prescaler(
         .sysclk(sysclk),
         .o_100khz_clk(w_100khz_clk)
    ); 
    
    wire w_100khz_clk;
    
     PWM_R(
     .i_addr(i_addr),
     .i_cs(i_cs),
     .i_pwm_value(i_pwm_value),
     .i_clk(i_clk),
     .o_pwm_reg(w_value)
    );
    
    wire [15:0] w_value;
    
    pwm_gen(
         .i_clk(w_100khz_clk),
         .i_en(i_en),
         .i_value(w_value),
         .o_pwm_clk(o_pwm_clk)
    );
    
endmodule
