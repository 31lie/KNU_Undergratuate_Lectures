// 컴퓨터학부 심화컴퓨터전공 2020114658 이윤서 (LEE Yoon Seo)

module three_bit_binary_counter_B (output [0:2] A, input Clk, clear);
    // declare wire and calculate
    wire TA;
    assign TA = A[1] || A[0];

    // match each of 3 Toggle flip flop 
    T_flip_flop M_A (A[0], 1'b1, Clk, clear);
    T_flip_flop M_B (A[1], A[0], Clk, clear);
    T_flip_flop M_C (A[2], TA, Clk, clear);

endmodule