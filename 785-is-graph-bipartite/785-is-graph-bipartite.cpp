class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(!dfs(i,graph,vis)){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool bfs(int n,vector<vector<int>>& graph,vector<int>& vis){
        queue<int>q;
        q.push(n);
        vis[n]=0;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(auto&i:graph[cur]){
                if(vis[i]==-1){
                    q.push(i);
                    vis[i]=(vis[cur]==0)?1:0;
                }
                else if(vis[i]==vis[cur]){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool dfs(int n,vector<vector<int>>& graph,vector<int>& vis){
        if(vis[n]==-1)
            vis[n]=1;
        
        for(auto&i:graph[n]){
            if(vis[i]==-1){
                vis[i]=1-vis[n];
                if(!dfs(i,graph,vis))
                    return false;
            }
            else if(vis[i]==vis[n]){
                return false;
            }
        }
        return true;
    }
};