class Solution {
public:
    bool canChange(string s, string t) {
        int i=0,j=0,n=s.length();
        while(i<n || j<n){
            while(s[i]=='_' && i<n) i++;
            while(t[j]=='_' && j<n) j++;
            
            if(i==n || j==n)
                break;
            if(s[i]!=t[j] || (s[i]=='L' && i<j) || (s[i]=='R' && i>j)){
                return false;
            }
            i++;
            j++;
        }

        return (i==n && j==n);
        
    }
};