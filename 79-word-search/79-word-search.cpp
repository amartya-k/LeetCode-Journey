class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool flag=false;
        vector<vector<bool>>vis(board.size(),vector<bool>(board[0].size(),false));
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(!flag){
                    solve(vis,board,word,i,j,0,flag);
                    vis= vector<vector<bool>>(board.size(),vector<bool>(board[0].size(),false));
                    // cout<<"In the loop: i , j :"<<i<<" ,"<<j<<endl;
                }
                else{
                    break;
                }
            }
        }
        return flag;
        
    }
    
    void solve(vector<vector<bool>>&vis,vector<vector<char>>& board, string word, int r, int c, int idx, bool &flag){
        //base
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || idx>=word.length() || board[r][c]!=word[idx] || flag==true || vis[r][c]==true){
            return;
        }
        //found
        if(word[idx]==board[r][c]){
           //cout<<board[r][c]<<endl;
            vis[r][c]=true;
            if(idx==word.length()-1){
                flag=true;
                return ;
            }
            solve(vis,board,word,r+1,c,idx+1,flag);
            solve(vis,board,word,r-1,c,idx+1,flag);
            solve(vis,board,word,r,c+1,idx+1,flag);
            solve(vis,board,word,r,c-1,idx+1,flag);
            vis[r][c]=false;
        }
    }
};

/*

[["A","B","C","E"],
["S","F","C","S"],
["A","D","E","E"]]



[["C","A","A"],
["A","A","A"],
["B","C","D"]]
AAB

[["A","B","C","E"],
["S","F","E","S"],
["A","D","E","E"]]
"ABCESEEEFS"

*/