// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    unordered_map<string,int>umap;
    int countWays(int N, string S){
        // code here
        return solve(S,0,N-1,true);
    }
    
    int solve(string &s,int i, int j, bool isTrue){
        if(i>j){
            return 0;
        }
        if(i==j){
            if (isTrue == true){
            return s[i] == 'T';
        }
        else {
            return s[i] == 'F';
        }
        }
        string temp=to_string(i)+to_string(j)+to_string(isTrue);
        if(umap.find(temp)!=umap.end()){
            return umap[temp];
        }
        
        int ans=0;
        for(int k=i+1;k<j;k+=2){
            int lt=solve(s,i,k-1,true);
            int lf=solve(s,i,k-1,false);
            int rt=solve(s,k+1,j,true);
            int rf=solve(s,k+1,j,false);
            
            if(s[k]=='^'){
                if(isTrue){
                    ans=ans+ lt*rf + lf*rt;
                }
                else{
                    ans=ans+lt*rt+lf*rf;
                }
            }
            else if(s[k]=='&'){
                if(isTrue){
                    ans=ans+lt*rt;
                }
                else{
                    ans=ans+lt*rf+lf*rf+lf*rt;
                }
            }
            else if(s[k]=='|'){
                if(isTrue){
                    ans=ans+lt*rt+lt*rf+lf*rt;
                }
                else{
                    ans=ans+lf*rf;
                }
            }
        }
        umap[temp]=ans%1003;
        return ans%1003;
    }
};

/*
xor:
F^T=1
T^F=1


*/















// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends