class Solution {
public:
//     int uniquePaths(int m, int n) {
//         vector<int> dp(n, 0);
//         dp[n-1]=1;
        
//         for(int i=m-1;i>=0;i--){
//             for(int j=n-1;j>=0;j--){
//                 if(j+1<=n-1)
//                     dp[j]+=dp[j+1];
                
//             }
//         }
//         return dp[0];
//     }
        int uniquePaths(int m, int n) {
            long long res=1,j=1;
            m--;
            n--;
            if(m<n)
                swap(m,n);
            
            
            for(long long i=m+1;i<=m+n;i++){
                res*=i;
                res/=j;
                j++;
            }
            return res;
            
        }
};

//(m+n)!/m!*n!