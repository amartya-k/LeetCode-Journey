class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>v;
        string s(n,'.');
        for(int i=0;i<n;i++){ 
            v.push_back(s); 
        }
        solve(res,v,0,n);
        return res;
        
    }
    
    void solve(vector<vector<string>>&res, vector<string>&v,int r,int n){
        if(r==n){
            res.push_back(v);
            return;
        }
        for(int c=0;c<n;c++){
            if(isSafe(v, r, c,n)){
            //if safe to place the queen, goto next row
                v[r][c]='Q';
                solve(res,v,r+1,n);
                v[r][c]='.';
            }
        }
        
    }
    
    bool isSafe(vector<string>&v,int r,int c,int n){
         //check rows
        for(int i=r;i>=0;i--){
            if(v[i][c]=='Q'){
                return false;
            }
        }
        
        //check left diagonal
        int i=r,j=c;
        while(i>=0 && j>=0){
            if(v[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        
        //check right diagonal
        i=r;
        j=c;
        while(i>=0 && j<n){
            if(v[i][j]=='Q'){
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
};