class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    count = count+1;
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, int r, int c){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]=='0'){
            return ;
        }
        //mark visited
        grid[r][c]='0';
        
        dfs(grid,r+1,c);
        dfs(grid,r-1,c);
        dfs(grid,r,c+1);
        dfs(grid,r,c-1);
    }
};
/*
  ["0","0","0","0","0"],
  ["0","0","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]

*/