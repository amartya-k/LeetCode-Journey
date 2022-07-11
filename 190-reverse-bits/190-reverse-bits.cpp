class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t a=0;
        int i=1;
        while(i<=32){
            a=a<<1;
            if(n && n&1){
                a=a|1;
            }
            n=n>>1;
            i++;
        }
        return a;
    }
};
/*
10101
00001
00010
00101

10101

01011


*/