class Solution {
public:
    int dp[50][50][51]; 
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return paths(startRow,startColumn,m,n,0,maxMove)%1000000007;
    }
    
    int paths(int r, int c, int m, int n, int rem, int maxMove){
        if(r<0 || c<0 || r>=m || c>=n){
            return 1;
        }
        if(rem==maxMove)
            return 0;
            
        if(dp[r][c][rem]!=-1)
            return dp[r][c][rem]%1000000007;
        long int temp=0;
        
        temp+=paths(r+1,c,m,n,rem+1,maxMove)%1000000007;
        temp+=paths(r-1,c,m,n,rem+1,maxMove)%1000000007;
        temp+=paths(r,c+1,m,n,rem+1,maxMove)%1000000007;
        temp+=paths(r,c-1,m,n,rem+1,maxMove)%1000000007;
        
        return dp[r][c][rem]=temp%1000000007;
    }
};