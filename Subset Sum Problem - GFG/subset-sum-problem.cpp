// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<vector<bool>>dp;
    Solution(){
        dp=vector<vector<bool>>(102,vector<bool>(100001,false));
    }
    bool isSubsetSum(vector<int>a, int sum){
        // code here 
        //return isSubset(arr,sum,arr.size());
        for(int i=0;i<=a.size();i++){
            dp[i][0]=true;
        }
        
        for(int i=1;i<=sum;i++){
            dp[0][i]=false;
        }
        
        //Main logic
        for(int i=1;i<=a.size();i++){
            for(int j=1;j<=sum;j++){
                if(a[i-1]<=j){
                    dp[i][j]=dp[i-1][j-a[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[a.size()][sum];
    }
    
    // bool isSubset(vector<int>a, int sum,int n){
    //     // code here 
    //     //Base
    //     if(sum==0)
    //     return true;
    //     else if(n<=0)
    //     return false;
        
    //     if(dp[n-1][sum]){
    //         return dp[n-1][sum];
    //     }
        
    //     if(a[n-1]<=sum){
    //         return dp[n-1][sum] = isSubset(a,sum-a[n-1],n-1) || isSubset(a,sum,n-1);
            
    //     }
    //     else{
    //         return dp[n-1][sum] = isSubset(a,sum,n-1);
    //     }
        
    // }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends