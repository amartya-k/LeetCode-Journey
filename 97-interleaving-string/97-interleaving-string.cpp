class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=(int)s1.size(),n2=(int)s2.size(),n3=(int)s3.size();
        if(n1+n2 != n3) return false;

        vector<vector<bool>>dp(n2+1, vector<bool>(n1+1,false));
        dp[0][0]=true;

        //base case update;
        //cols
        for(int i=1;i<n1+1;i++){
            dp[0][i]= dp[0][i-1] && s1[i-1]==s3[i-1];
        }
        //rows
        for(int i=1;i<n2+1;i++){
            dp[i][0]= dp[i-1][0] && s2[i-1]==s3[i-1];
        }

        //actual logic
        for(int i=1;i<n2+1;i++){
            for(int j=1;j<n1+1;j++){
                dp[i][j]=(dp[i][j-1]&&s1[j-1]==s3[i+j-1])||(dp[i-1][j]&&s2[i-1]==s3[i+j-1]);
            }
        }

        return dp[n2][n1];
    }
};
    
//     bool isInterleave(string s1, string s2, string s3) {
//         int n1 = (int)s1.size(), n2 = (int)s2.size(), n3 = (int)s3.size(); 
//         if(n1 + n2 != n3) return false;
        
//         vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
//         dp[0][0] = true;
        
//         for(int i2 = 1; i2 <= n2; i2++) dp[0][i2] = dp[0][i2 - 1] && s2[i2 - 1] == s3[i2 - 1];
//         for(int i1 = 1; i1 <= n1; i1++) dp[i1][0] = dp[i1 - 1][0] && s1[i1 - 1] == s3[i1 - 1];

//         for(int i1 = 1; i1 <= n1; i1++){
//             for(int i2 = 1; i2 <= n2; i2++){
//                 dp[i1][i2] = (dp[i1 - 1][i2] && s1[i1 - 1] == s3[i1 + i2 - 1]) || (dp[i1][i2 - 1] && s2[i2 - 1] == s3[i1 + i2 - 1]);
//             }
//         }
        
//         return dp[n1][n2];  
//     }
// };
/*

    "" a a b c c
""  1  1 1 0 0 0
d   0  0 1 1
b
b
c
a
------
[true, true]


*/