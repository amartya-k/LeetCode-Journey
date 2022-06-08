class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        //vector<vector<int>>a(n,vector<int>(m,0));
        bool f=true;
        
        for(int i=0;i<n;i++){
            if(mat[i][0]==0)
                f=false;
            for(int j=1;j<m;j++){
                if(mat[i][j]==0){
                    mat[0][j]=0;
                    mat[i][0]=0;
                }
            }
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=1;j--){
                if(mat[0][j]==0 || mat[i][0]==0)
                    mat[i][j]=0;
            }
            if(!f){
                mat[i][0]=0;
            }
        }
        
        
    }
};

/*
[[1,2,3,4],
[5, 0, 7, 8],
[0,10,11,12],
[13,14,15,0]]

[[0,0,3,0],
[0, 0, 0, 0],
[0,0,11,0],
[0,0,15,0]]





*/