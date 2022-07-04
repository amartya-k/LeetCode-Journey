// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	   // stack<int>s;
	   // vector<bool>vis(V);
	   // vector<int>r;
	   // for(int i=0;i<V;i++){
	   //     if(!vis[i]){
	   //         dfs(i,adj,s,vis);
	   //     }
	   // }
	   // while(!s.empty()){
	   //     r.push_back(s.top());
	   //     s.pop();
	   // }
	   // return r;
	   //Above code is for DFS algo
	   
	   //BFS method or Kahn's Algo
	   
	   //1. count in-degrees
	   vector<int>in(V,0);
	   vector<int>res;
	   queue<int>q;
	   
	   for(int i=0;i<V;i++){
	       for(auto a:adj[i]){
	           in[a]++;
	       }
	   }
	   
	   for(int i=0;i<V;i++){
	       if(in[i]==0){
	           q.push(i);
	       }
	   }
	   
	   while(!q.empty()){
	       int node=q.front();
	       q.pop();
	       res.push_back(node);
	       for(auto i:adj[node]){
	           in[i]--;
	           if(in[i]==0){
	               q.push(i);
	           }
	       }
	   }
	   return res;
	   
	   
	}
	
	void dfs(int n, vector<int> adj[], stack<int>&s, vector<bool>&vis){
	    vis[n]=true;
	    
	    for(auto&i:adj[n]){
	        if(!vis[i]){
	            dfs(i,adj,s,vis);
	            
	        }
	    }
	    s.push(n);
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends