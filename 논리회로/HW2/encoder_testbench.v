/******************* 
컴퓨터학부 심화컴퓨터전공 
2020114658 이윤서
********************/

// testbench description of 4-input priority encoder for two kinds

module t_4_input_priority_encoder;
    // Set Output for two different models
    wire t_x1, t_y1, t_V1;
    wire t_x2, t_y2, t_V2;
    
    // Set input
    // There are two models, but we have same input value so we can set only one kind of input.
    reg [0:3] t_D;
    
    // Circuits to be tested
    encoder_4_input_df DF(t_D, t_x1, t_y1, t_V1);
    encoder_4_input_gates GL(t_D, t_x2, t_y2, t_V2);

    initial begin
        // There are 4 bits for t_D
        t_D = 4'b0000;
        // 0000 ~ 1111 1 + 15(repeat)
        repeat(15)
        // wait 10nsec, add 0001 for value change
        #10 t_D = t_D + 4'b0001;
    end

    initial begin
        //print value whenever values are change with specific format
        $monitor("D0 D1 D2 D3 = %b %b %b %b x1 y1 V1 = %b %b %b x2 y2 V2 = %b %b %b",t_D[0],t_D[1],t_D[2],t_D[3],t_x1,t_y2,t_V1,t_x2,t_y2,t_V2);
    end

endmodule