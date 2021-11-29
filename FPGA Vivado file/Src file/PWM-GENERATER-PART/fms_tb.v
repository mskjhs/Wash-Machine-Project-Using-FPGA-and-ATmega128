`timescale 1ns / 1ps

module fms_tb(

    );

    reg sysclk;
    reg i_sw;
    wire [1:0] w_pwm_duty;

    FSM_PWM fsm(
    .sysclk(sysclk),
    .i_sw(i_sw),
    .o_pwm_duty(w_pwm_duty)
    );

    always #5 sysclk = ~sysclk;

    initial begin
        #0
        sysclk = 0;
        i_sw = 1;
        #100
        i_sw = 0;
        #100
        i_sw = 1;
        #100
        i_sw = 0;
        #100
        i_sw = 1;
        #100
        i_sw = 0;
        #100
        i_sw = 1;
        #100
        i_sw = 0;
        #100
        i_sw = 1;
        #100
        i_sw = 0;
        #100
        i_sw = 1;
        #100
        i_sw = 0;
        #100
        i_sw = 1;
        #100
        i_sw = 0;
        #100
        i_sw = 1;
        #100
        i_sw = 0;
        #100
        i_sw = 1;
        #100
        i_sw = 0;
        #100
        i_sw = 1;
        #100
        i_sw = 0;
        #100
        i_sw = 1;
        #100
        i_sw = 0;
        #100
        i_sw = 1;
        #100
        i_sw = 0;
        #100
        i_sw = 1;
        #100
        i_sw = 0;
        #100
        i_sw = 1;
        #100
        i_sw = 0;
        #100
        i_sw = 1;
        #100
        i_sw = 0;
        #100
        i_sw = 1;
        #100
        i_sw = 0;
        #100
        i_sw = 1;
        #100
        i_sw = 0;
        #100
        i_sw = 1;

    end

endmodule
