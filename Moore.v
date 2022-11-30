// Ha Vi Nguyen - 2013907
module detect1011 (output out, input in, clk, rst);
    reg[2:0] state, next_state;
    parameter s0 = 0, s1 = 1, s2 = 2, s3 = 3, s4 = 4;
    // Moore
    always @(negedge clk) begin
        if(rst == 1) state <= s0;
        else state = next_state;
    end

    always @(state or in) begin
        next_state = s0;
        case(state)
            s0: if(in == 1) next_state = s1;
            else next_state = s0;
            s1: if(in == 1) next_state = s1;
            else next_state = s2;
            s2: if(in == 1) next_state = s3;
            else next_state = s0;
            s3: if(in == 1) next_state = s4;
            else next_state = s2;
            s4: if(in == 1) next_state = s1;
            else next_state = s2;
            default: next_state = s0;
    end
    assign out = (state == s4);
endmodule