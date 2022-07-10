class Solution {
public:
    int minCostClimbingStairs(vector<int>& c) {
        if(c.size()==2)
            return min(c[0],c[1]);
        int temp=0,a=c[0],b=c[1];
        
        for(int i=2;i<c.size();i++){
            temp= c[i] + min(a,b);
            a=b;
            b=temp;
        }
        return min(a,b);
    }
};