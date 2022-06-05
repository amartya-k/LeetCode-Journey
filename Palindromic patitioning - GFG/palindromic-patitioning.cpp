// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>>dp;
    Solution(){
        dp=vector<vector<int>>(501,vector<int>(501,-1));
    }

    int palindromicPartition(string str)
    {
        // code here
       // vector<vector<int>>dp(str.length(),vector<int>(str.length(),-1));
        return solve(str,0,str.length()-1);
    }
    
    bool palin(string &s,int i, int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string s, int i, int j){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(palin(s,i,j)){
            return 0;
        }
        int left, right;
        int mn=INT_MAX;
        for(int k=i;k<=j-1;k++){
            if(dp[i][k]!=-1)
                left=dp[i][k];
            else
                left=solve(s,i,k);
                
            if(dp[k+1][j]!=-1)
                right=dp[k+1][j];
            else
                right=solve(s,k+1,j);
            
            mn=min(mn,left+right+ 1);
        }
        
        return dp[i][j]=mn;
    }
    
    
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends