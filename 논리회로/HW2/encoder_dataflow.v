/******************* 
컴퓨터학부 심화컴퓨터전공 
2020114658 이윤서
********************/

// Dataflow description of 4-input priority encoder

module encoder_4_input_df(
    //Set input and output
    input [0:3] D,
    output x, y, V
);
    //assign for dataflow model
    assign 
        //Use operators 
        x = D[2] || D[3],                       // x = D2 + D3
        y = D[3] || (D[1] && !(D[2])),          // y = D3 + D1D2'
        V = D[0] || D[1] || D[2] || D[3];       // V = D0 + D1 + D2 + D3
endmodule
