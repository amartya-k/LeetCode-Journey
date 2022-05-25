// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int cn[], int M, int V) 
	{ 
	    // Your code goes here
	    int n=M;
        vector<vector<int>>dp(n+1,vector<int>(V+1,0));
        for(int i=1;i<V+1;i++){
            dp[0][i]=V+1;
        }
        
        //main logic
        for(int i=1;i<n+1;i++){
            for(int j=0;j<V+1;j++){
                if(j>=cn[i-1]){
                    dp[i][j]= min(dp[i-1][j],1 + dp[i][j-cn[i-1]]);
                    
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        // for(auto i:dp){
        //     for(auto j:i)
        //     cout<<j<<" ";
        //     cout<<endl;
        // }
        
        
        return dp[n][V]==V+1?-1:dp[n][V];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends