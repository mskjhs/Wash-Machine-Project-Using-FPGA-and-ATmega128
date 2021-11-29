`timescale 1ns / 1ps

module shiftRegister(
    input i_mosi,
    input i_shift_clk,
    input i_ss, 
    output [7:0] o_data
    );

    reg [7:0] r_data = 0;
    reg [7:0] t_data = 0;

    assign o_data = t_data;

    always @(posedge i_shift_clk) begin
        if (i_shift_clk) begin
            r_data <= {r_data[6:0], i_mosi};
        end
    end

    always @(posedge i_ss) begin
        if (i_ss) begin
            t_data <= r_data;
        end
    end
    

endmodule
