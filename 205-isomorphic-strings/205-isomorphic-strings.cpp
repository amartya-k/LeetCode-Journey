class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())
            return false;
        
        return f(s,t)&&f(t,s);
    }
    bool f(string s, string t){
        unordered_map<char,int>umap;

        for(int i=0;i<t.length();i++){
            if(umap.find(s[i])!=umap.end()){
                if(umap[s[i]]!=t[i]){
                    return false;
                }
            }
            else{
                umap[s[i]]=t[i];
            }
        }
        return true;
    }
};

/*
"bbbaaaba" ---true
"aaabbbba" 

"foo"
"bar"  --false




*/