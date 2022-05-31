// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    //int solve(int a[],int , int);
    vector<vector<int>>dp;
    Solution(){
        dp=vector<vector<int>>(101,vector<int>(101,-1));
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        return solve(arr,1,N-1);
    }
    
    int solve(int a[],int i, int j){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int t,mn=INT_MAX;
        
        for(int k=i;k<=j-1;k++){
            t=solve(a,i,k)+solve(a,k+1,j)+a[i-1]*a[k]*a[j];
            mn=min(t,mn);
        }
        return dp[i][j]=mn;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends