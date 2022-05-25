class Solution {
public:
    int coinChange(vector<int>& cn, int V) {
        int n=cn.size();
        vector<vector<int>>dp(n+1,vector<int>(V+1,0));
        for(int i=1;i<V+1;i++){
            dp[0][i]=V+1;
        }
        
        //main logic
        for(int i=1;i<n+1;i++){
            for(int j=0;j<V+1;j++){
                if(j>=cn[i-1]){
                    dp[i][j]= min(dp[i-1][j], 1+ dp[i][j-cn[i-1]]);
                    
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        
        return dp[n][V]==V+1?-1:dp[n][V];
    }
};