//Ha Vi Nguyen - 2013907
module Detect (output Dout, input Din, En, clk, reset);
parameter s0 = 0, s1 = 1, s2 = 2, s31 = 3, s32 = 4,
    s4 = 5, s5 = 6, s6 = 7, s7 = 8, s8 = 9;
    reg[3: 0] state, next_state;
always @(negedge clk)
    if (reset == 1) state <= s0;
    else state <= next_state;

always @(state, Din, En) begin
    case(state)
    s0: if ((En == 1) && (Din == 1)) next_state = s1;
    else if((En == 1) && (Din == 0)) next_state = s0;
    else next_state = s0;
    s1:if (Din == 0) next_state = s2;
    else if (Din == 1) next_state = s1;
    else next_state = s0;
    s2:if (Din == 0) next_state = s31;
    else if (Din == 1) next_state = s32;
    else next_state = s0;
    s31:if (Din == 0) next_state = s5;
    else if (Din == 1) next_state = s4;
    else next_state = s0;
    s32:if (Din == 0) next_state = s2;
    else if (Din == 1) next_state = s4;
    else next_state = s0;
    s4:if (Din == 0) next_state = s2;
    else if (Din == 1) next_state = s1;
    else next_state = s0;
    s5:if (Din == 0) next_state = s8;
    else if (Din == 1) next_state = s6;
    else next_state = s0;
    s6:if (Din == 0) next_state = s7;
    else if (Din == 1) next_state = s1;
    else next_state = s0;
    s7:if (Din == 0) next_state = s31;
    else if (Din == 1) next_state = s32;
    else next_state = s0;
    s8:if (Din == 0) next_state = s5;
    else if (Din == 1) next_state = s1;
    else next_state = s0;
    default: next_state = s0;
    endcase
end
assign Dout = (((state == s4) || (state == s7)) && (Din == 1 ));
endmodule