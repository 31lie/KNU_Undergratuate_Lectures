// 컴퓨터학부 심화컴퓨터전공 2020114658 이윤서 (LEE Yoon Seo)
// make module of T_flip flop

module T_flip_flop (Q, T, Clk, Rst_b);
    output Q;
    input T, Clk, Rst_b;
    reg Q;

    always @ (posedge Clk, negedge Rst_b)
        if (Rst_b == 0) Q <= 1'b0;
        else if (T) Q <= ~Q;
endmodule