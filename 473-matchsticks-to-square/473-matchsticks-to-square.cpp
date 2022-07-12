class Solution {
public:
    
    bool makesquare(vector<int>& mat) {
        int sum,a;
        sum = accumulate(mat.begin(),mat.end(),0);
        if(sum&1) return false;
        a=sum/4;
        vector<int>s(4,0);
        
        sort(mat.begin(),mat.end(),greater<int>());
        if (mat[0] > a) return false;
        return solve(0,mat,a,s);
    }
    
    bool solve(int i, vector<int>& mat, int a, vector<int>&s){
        if(i==mat.size())
            return true;
        
        for(int j=0;j<4;j++){
            if(s[j]+mat[i]<=a){
                
                int p = j;
                while (--p >= 0) // third
                    if (s[j] == s[p]) 
                        break;
                if (p != -1) continue;
                
                s[j]+=mat[i];
                if(solve(i+1,mat,a,s))
                    return true;
                s[j]-=mat[i];
            }
        }
        return false;
    }
};