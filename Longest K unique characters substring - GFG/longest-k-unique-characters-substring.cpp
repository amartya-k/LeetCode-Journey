// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    unordered_map<char,int>umap;
    int i=0,j=0,mx=-1,unq=0;
    
    //sliding window
    while(j<s.length()){
        //insert &count unique
        umap[s[j]]++;
        
        //making the unique elements <=k
        while(i<=j && umap.size()>k){
            umap[s[i]]--;
            if(umap[s[i]]<=0){
                umap.erase(s[i]);
            }
            i++;
        }
        //window hit
        if(umap.size()==k){
            mx=max(mx,j-i+1);
        }
        j++;
    }
    return mx;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends