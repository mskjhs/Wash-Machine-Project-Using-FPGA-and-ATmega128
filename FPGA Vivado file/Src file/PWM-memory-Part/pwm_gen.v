`timescale 1ns / 1ps

module pwm_gen(
    input i_clk,
    input i_en,
    input [15:0]i_value,
    output o_pwm_clk
    );
    reg [31:0] counter =0;
   // reg [31:0] r_value = 1000;
    reg r_pwm_clk;
    
    assign o_pwm_clk = r_pwm_clk;
    
    always @(posedge i_clk) begin
        if(i_en == 1) begin
              if(counter >= (100000/i_value) - 1)begin
                  counter <= 0;
                  r_pwm_clk = 1;
              end
              else begin
                  counter <= counter + 1;
                  if (counter >= 100000/i_value/2 -1)
                      r_pwm_clk <= 0;
              end
         end
         else r_pwm_clk <= 1'b0;
    end
endmodule
