class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int>v(26);
        
        for(int i=0;i<s.length();i++){
            v[s[i]]++;
        }
        
        for(int i=0;i<t.length();i++){
            if(--v[t[i]]<0) 
                return false;
        }
        
        return true;
    }
};