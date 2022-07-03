class Solution {
public:
       bool dfs(int n, vector<vector<int>>& adj, vector<int>&vis, vector<int>&d_vis){
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
    bool canFinish(int V, vector<vector<int>>& pre) {
         vector<int>vis(V+1,0);
        vector<int>d_vis(V+1,0);
        vector<vector<int>>adj(V);
        
        for(auto&i:pre){
            adj[i[1]].push_back(i[0]);
        }
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,d_vis)){
                    return false;
                }
            }
        }
        return true;
    }
};