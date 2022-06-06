class Solution {
public:
    vector<vector<int>>dp;
    vector<vector<bool>>pd;
    
    int minCut(string s) {
        dp=vector<vector<int>>(s.length(),vector<int>(s.length(),-1));
        pd=vector<vector<bool>>(s.length(),vector<bool>(s.length(),false));
        
        //cal palindromes
        for(int i=0;i<s.length();i++){
            for(int j=0;j<s.length();j++){
                pd[i][j]= palin(s,i,j) ? true:false;
            }
        }
        
        
        return solve(s,0,s.length()-1);
    }
    
    bool palin(string &s,int i, int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string &s, int i, int j){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(pd[i][j]){
            return 0;
        }
        int left;
        int mn=INT_MAX;
        for(int k=i;k<=j-1;k++){
            if(palin(s,i,k)){
                left=solve(s,k+1,j);
                mn=min(mn,left+1);
            }
        }
        
        return dp[i][j]=mn;
    }
};