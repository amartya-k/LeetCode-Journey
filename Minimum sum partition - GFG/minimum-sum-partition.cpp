// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int a[], int n)  { 
	    // Your code goes here
	    int total=0;
	    for(int i=0;i<n;i++)
	        total+=a[i];
	    
	    vector<vector<bool>>dp(n+1, vector<bool>(total+1,false));
	    
	    for(int i=0;i<dp.size();i++){
	       dp[i][0]=true;
	    }
	    
	    for(int i=1;i<n+1;i++){
	        for(int j=1;j<total+1;j++){
	            if(a[i-1]<=j){
	                dp[i][j]= dp[i-1][j] || dp[i-1][j-a[i-1]];
	            }
	            else{
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	   
	    int mn=INT_MAX;
	    for(int i=0;i<total+1;i++){
	        if(dp[n][i]){
	            //cout<<i<<endl;
	            mn=min(mn,abs(total-2*i));
	        }
	    }
	    
	    return mn;     
	}
	
	
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends