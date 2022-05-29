// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}// } Driver Code Ends


int minDeletions(string A, int n) { 
    //complete the function here 
    string B=A;
    reverse(B.begin(),B.end());
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(A[i-1]==B[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return n-dp[n][n];
} 