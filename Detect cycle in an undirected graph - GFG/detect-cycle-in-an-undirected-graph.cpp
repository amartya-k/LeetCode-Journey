// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
      bool isCycle(int node,vector<int>adj[],vector<bool>&vis){
        queue<pair<int,int>>q;
        q.push({node,-1});
        vis[node]=true;
        
        while(!q.empty()){
            int cur=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto& i:adj[cur]){
                if(!vis[i]){
                    q.push({i,cur});
                    vis[i]=true;
                    
                }
                else if(i!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(int node,int prev,vector<int>adj[],vector<bool>&vis){
        vis[node]=true;
        
        for(auto& i:adj[node]){
            if(!vis[i]){
                  if(dfs(i,node,adj,vis)) return true;
            }
            else if(i!=prev){
                return true;
            }
        }
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,-1,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
    

};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends