// 컴퓨터학부 심화컴퓨터전공 2020114658 이윤서 (LEE Yoon Seo)


module t_3_bit_binary_counter;

    // declare input and output of testbench
    wire [2:0] t_A_y_out;
    wire [2:0] t_B_A;
    reg t_Clk, t_clear;

    // set the module for test
    three_bit_binary_counter_A MA(t_A_y_out,t_Clk,t_clear);
    three_bit_binary_counter_B MB(t_B_A, t_Clk,t_clear);

    // set finish time
    initial #300 $finish;

    initial begin
        // make wave file
        $dumpfile("2020114658.vcd");
        $dumpvars;

        // change var
        t_clear = 1'b0;
        t_Clk = 1'b0;
        #5 t_clear = 1'b1;c
        repeat(50)
            #5 t_Clk = ~t_Clk;
    end

    initial begin
        // print whenever var is change
        $monitor ("A2 A1 A0 = %b %b %b\tA2 A1 A0 = %b %b %b", t_A_y_out[2], t_A_y_out[1], t_A_y_out[0], t_B_A[2], t_B_A[1], t_B_A[0]);
    end
endmodule



