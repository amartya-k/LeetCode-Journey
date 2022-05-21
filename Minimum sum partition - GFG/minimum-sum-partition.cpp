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
	    //cout<<total<<endl;
	    //vector<vector<bool>>dp(n+1, vector<bool>(total+1,false));
	    int mid=(total/2)+1;
	    vector<bool>dp1(mid,false);
	    vector<bool>dp2(mid,false);
	    
	    dp1[0]=true;
	    dp2[0]=true;
	    
	    for(int i=1;i<n+1;i++){
	        for(int j=1;j<mid;j++){
	            if(a[i-1]<=j){
	                //dp[i][j]= dp[i-1][j] || dp[i-1][j-a[i-1]];
	                dp2[j] = dp1[j] || dp1[j-a[i-1]];
	            }
	            else{
	                dp2[j]=dp1[j];
	            }
	           
	        }
	         dp1=dp2;
	    }
	    
	   
	    int mn=INT_MAX;
	    for(int i=dp2.size()-1;i>=0;i--){
	        if(dp2[i]){
	            //cout<<i<<endl;
	            mn=min(mn,abs(total-2*i));
	            break;
	            
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