`timescale 1ns / 1ps

module PWM_Generator(
    input sysclk,
    input i_rst_n,
    input [1:0] i_sw,
    output o_pwm_out,
    output [3:0] o_fndSelect,
    output [7:0] o_fndFont
    );

    prescaler clk_1Mhz(
    .sysclk(sysclk),
    .i_rst_n(i_rst_n),
    .o_1Mhz_clk(w_1Mhz_clk)
    );
/*
    wire w_1Mhz_clk;

    FSM_PWM pwm_fsm(
    .sysclk(sysclk),
    .i_sw(i_sw),
    .o_pwm_duty(w_pwm_duty)
    );
*/
 //   wire [1:0] w_pwm_duty;

    PWM_Gen pwm(
    .i_1Mhz_clk(w_1Mhz_clk),
    .i_rst_n(i_rst_n),
    .i_pwm_duty(i_sw),
    .o_pwm_out(o_pwm_out)
    );

    PWMtoFND to_fnd(
    .i_pwm_duty(i_sw),
    .o_pwm_to_fnd(w_pwm_to_fnd)
    );

    wire [13:0] w_pwm_to_fnd;

    FND_Display display(
    .sysclk(sysclk),
    .i_rst_n(i_rst_n),
    .i_fndData(w_pwm_to_fnd),
    .o_fndSelect(o_fndSelect),
    .o_fndFont(o_fndFont)
    );


endmodule
