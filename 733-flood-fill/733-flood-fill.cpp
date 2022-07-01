class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
    
    void dfs(vector<vector<int>>& img, int r, int c, int col, int prev){
        if(r>=img.size() || c>=img[0].size() || r<0 || c<0 ||img[r][c]!=prev || img[r][c] ==col)
            return;
        prev=img[r][c];
        img[r][c]=col;
        
        dfs(img,r+1,c,col,prev);
        dfs(img,r-1,c,col,prev);
        dfs(img,r,c+1,col,prev);
        dfs(img,r,c-1,col,prev);
    }
};