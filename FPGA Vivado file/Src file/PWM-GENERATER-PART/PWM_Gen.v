`timescale 1ns / 1ps

module PWM_Gen(
    input i_1Mhz_clk,
    input i_rst_n,
    input [1:0] i_pwm_duty,
    output o_pwm_out
    );

    reg r_pwm_out = 1;
    reg [6:0] r_pwm_counter = 0;
    reg [6:0] r_out_compare = 0;

    assign o_pwm_out = r_pwm_out;

    always @(posedge i_1Mhz_clk or negedge i_rst_n) begin
        if (!i_rst_n) begin
            r_pwm_counter <= 0;
            r_pwm_out <= 0;
        end
        else begin
            if (r_pwm_counter >= 100 - 1) begin
                r_pwm_counter <= 0;
                //r_pwm_out <= ~r_pwm_out;
            end
            else begin
                r_pwm_counter <= r_pwm_counter + 1;
                if (r_pwm_counter < r_out_compare) begin
                    r_pwm_out <= 1;
                end
                else begin
                    r_pwm_out <= 0;
                end
            end
        end
    end

    always @(i_pwm_duty) begin
        case (i_pwm_duty)
            0 : r_out_compare <= 0;
            1 : r_out_compare <= 40;
            2 : r_out_compare <= 70;
            3 : r_out_compare <= 95;
        endcase
    end
endmodule
