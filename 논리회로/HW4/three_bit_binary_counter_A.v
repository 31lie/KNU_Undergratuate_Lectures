// 컴퓨터학부 심화컴퓨터전공 2020114658 이윤서 (LEE Yoon Seo)

module three_bit_binary_counter_A (output[2:0] y_out, input Clk, clear);

    // declare var and constant var
    reg[2:0] state;
    // state
    parameter S0 = 3'b000, S1 = 3'b001, S2 = 3'b010, S3 = 3'b011, S4 = 3'b100, S5 = 3'b101, S6 = 3'b110, S7 = 3'b111;

    // execute when Clk(0->1) or clear(1->0) is change
    always @ (posedge Clk, negedge clear)
        // initialize state
        if (clear == 0) state <=S0;
        else case (state)
            // 3bit binary count
            S0 : state <= S1;
            S1 : state <= S2;
            S2 : state <= S3;
            S3 : state <= S4;
            S4 : state <= S5;
            S5 : state <= S6;
            S6 : state <= S7;
            S7 : state <= S0;
        endcase
    // set output
    assign y_out = state;
endmodule


