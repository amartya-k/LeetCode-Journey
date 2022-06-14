class Solution {
public:
    int minDistance(string s1, string s2) {
        int n=s1.length(),m=s2.length(),mx=INT_MIN;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
               
            }
        }
        if((dp[n][m]==n && m==n )|| (dp[n][m]==m && m==n)){
            return 0;
        }
        
        return m+n-2*dp[n][m];
    }
};