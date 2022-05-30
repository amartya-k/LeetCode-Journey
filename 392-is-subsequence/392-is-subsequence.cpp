class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.length(),m=t.length();
        int j=0;
        for(int i=0;i<m;i++){
            if(j==n){
                break;
            }
            else if(s[j]==t[i]){
                j++;
            }
        }
        return j==n?true:false;
    }
};