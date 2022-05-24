// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int count(int S[], int tcoins, int w) {

        // code here.
        
        // vector<vector<long long int>>dp(tcoins+1,vector<long long int>(w+1,0));
        // for(int i=0;i<tcoins+1;i++){
        //     dp[i][0]=1;
        // }
        
        // //main logic
        // for(int i=1;i<tcoins+1;i++){
        //     for(int j=0;j<w+1;j++){
        //         if(j>=S[i-1]){
        //             dp[i][j]= dp[i-1][j] + dp[i][j-S[i-1]];
                    
        //         }
        //         else{
        //             dp[i][j]=dp[i-1][j];
        //         }
        //     }
        // }
        // return dp[tcoins][w];
        vector<long long int>dp(w+1,0);
        dp[0]=1;
        
        for(int i=0;i<tcoins;i++){
            for(int j=S[i];j<=w;j++){
                dp[j]+=dp[j-S[i]];
            }
        }
        return dp[w];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends