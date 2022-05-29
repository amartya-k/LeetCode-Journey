class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m=s1.length(),n=s2.length();
        string res="";
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int r=m,c=n;
        while(r>0 && c>0){
            if(s1[r-1]==s2[c-1]){
                res = s1[r-1]+res;
                r--;
                c--;
            }
            else{
                if(dp[r-1][c]>dp[r][c-1]){
                    res = s1[r-1] + res;
                    r--;
                }
                else{
                    res = s2[c-1] + res;
                    c--;
                }
            }
        }
    
    
    while(r>0){
        res= s1[r-1] + res;
        r--;
    }
    while(c>0){
        res = s2[c-1]+res;
        c--;
    }
    return res;
    }
};