`timescale 1ns / 1ps

module prescaler(
    input sysclk,
    input i_rst_n,
    output o_1Mhz_clk
    );
    
    reg r_1Mhz_clk;
    reg [5:0] counter = 0;

    assign o_1Mhz_clk = r_1Mhz_clk;

    always @(posedge sysclk or negedge i_rst_n) begin
        if (!i_rst_n) begin
            counter <= 0;
        end
        else begin
            if (counter >= 60 - 1) begin
                counter <= 0;
                r_1Mhz_clk <= ~r_1Mhz_clk;
            end
            else begin
                counter <= counter + 1;
            end
        end

    end
endmodule
