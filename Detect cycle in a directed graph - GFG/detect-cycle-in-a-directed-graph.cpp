// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    bool dfs(int n, vector<int> adj[], vector<int>&vis, vector<int>&d_vis){
        vis[n]=1;
        d_vis[n]=1;
        
        for(auto& i:adj[n]){
            if(!vis[i]){
                if(dfs(i,adj,vis,d_vis))
                    return true;
            }
            else if(vis[i]==1 && d_vis[i]==1){
                return true;
            }
        }
        d_vis[n]=0;
        return false;
        
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        vector<int>d_vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,d_vis)){
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends