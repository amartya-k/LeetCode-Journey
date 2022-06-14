// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    unordered_map<char,int>umap;
	    for(auto& i:pat)
            umap[i]++;
        
        int i=0,j=0, count=umap.size(),k=pat.length(), ans=0;
        while(j<txt.length()){
            //calculations
            if(umap.find(txt[j])!=umap.end()){
                umap[txt[j]]--;
                if(umap[txt[j]]==0)
                    count--;
            }
            
            //window hits
            if(j-i+1==k){
                if(count==0){
                    ans++;
                }
                if(umap.find(txt[i])!=umap.end()){
                    umap[txt[i]]++;
                    if(umap[txt[i]]==1){
                        count++;
                    }
                }
                
                i++;
            }
            j++;
        }
	   
	   return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends