`timescale 1ns / 1ps

module prescaler(
    input sysclk,
    output o_100khz_clk
    );  
    reg  r_100khz_clk =0;
    reg  [5:0]counter =0;
    assign o_100khz_clk = r_100khz_clk;
    always @(posedge sysclk)begin
        if(counter >= 60-1) begin
            counter <= 0;
            r_100khz_clk <= ~r_100khz_clk;
        end
        else begin
            counter <= counter + 1;
        end
     end
endmodule
