class Solution {
public:
    
    int climbStairs(int n) {
        int one=1,two=1;
        for(int i=0;i<n-1;i++){
            two=one+two;
            swap(one,two);
        }
        return one;
    }
    
};
/*

3=
1+1+1
1+2
2+1

*/