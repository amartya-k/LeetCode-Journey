class Solution {
public:
    int divide(int dd, int dv) {
        if (dd == INT_MIN && dv == -1) {
            return INT_MAX;
        }
        long long count=0,res=0, divd=labs(dd),div=labs(dv);
        int sign= (dd>0)^(dv>0) ? -1:1;
        
        while(divd>=div){
            count=1;
            long t=div;
            while(t<<1 <= divd){
                t<<=1;
                count<<=1;
            }
            res+=count;
            divd-=t;
            
        }
        
        return res*sign;
    }
};

/*
10 10  10
3  6   12

10-6=4

4 3
3 6

4-3

1
3


*/