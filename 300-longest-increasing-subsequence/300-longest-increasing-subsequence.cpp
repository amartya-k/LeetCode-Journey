class Solution {
public:
    int lengthOfLIS(vector<int>& v1) {
       vector<int>v2=v1;
        int n=v1.size();
        
        
        sort(v2.begin(),v2.end());
        auto ip = unique(v2.begin(), v2.begin() + n);
        v2.resize(distance(v2.begin(), ip));
        int m=v2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(v1[i-1]==v2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    

};