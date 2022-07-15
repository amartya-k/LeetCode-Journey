class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0,area=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    area=0;
                    dfs(i,j,grid,area);
                    ans=max(ans,area);
                }
            }
        }
        return ans;
    }
    
    void dfs(int r, int c, vector<vector<int>>& grid, int& area){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || !grid[r][c])
            return;
        
        grid[r][c]=0;
        area++;
        
        dfs(r+1,c,grid,area);
        dfs(r-1,c,grid,area);
        dfs(r,c+1,grid,area);
        dfs(r,c-1,grid,area);
    }
};