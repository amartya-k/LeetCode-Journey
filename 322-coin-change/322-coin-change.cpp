class Solution {
public:
    int coinChange(vector<int>& cn, int V) {
        vector<int>dp(V+1,V+1);
        dp[0]=0;
        
        for(int i=1;i<V+1;i++){
            for(int j=0;j<cn.size();j++){
                if(i>=cn[j])
                    dp[i]=min(dp[i],1+dp[i-cn[j]]);
            }
        }
        return dp[V]==V+1?-1:dp[V];
    }
};