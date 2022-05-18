// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int perfectSum(int v[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n+1, vector<int>(sum+1,0));
        long long int mod=1000000007;
        for(int i=0;i<n+1;i++){
            dp[i][0]=1;
        }
        //main logic
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(v[i-1]<=j){
                    dp[i][j]= dp[i-1][j-v[i-1]]%mod + dp[i-1][j]%mod;
                }
                else{
                dp[i][j]=dp[i-1][j]%mod;
                }
            }
        }
        // for(auto i:dp){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return dp[n][sum]%mod;
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends