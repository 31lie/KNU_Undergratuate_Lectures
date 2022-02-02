/******************* 
컴퓨터학부 심화컴퓨터전공 
2020114658 이윤서
********************/

// Gate-level description of 4-input priority encoder

module encoder_4_input_gates(
    // Set input and Output
    input [0:3] D,
    output x, y, V
);
    // Use wire for calculating x, y, V
    wire D2_not, D1_D2, D2_D3;
    not 
        G1(D2_not, D[2]);
    and 
        G2(D1_D2, D2_not, D[1]);
    or 
        G3(y, D[3], D1_D2),
        G4(D2_D3, D[3], D[2]),
        G5(V, D2_D3, D[1], D[0]),
        G6(x, D[3], D[2]);
endmodule



