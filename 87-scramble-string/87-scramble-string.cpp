class Solution {
public:
    unordered_map<string,bool>umap;
    bool isScramble(string s1, string s2) {
        if(s1.compare(s2)==0)
            return true;
        if(s1.length()<=1)
            return false;
        string key=s1+" "+s2;
        if(umap.find(key)!=umap.end()){
            return umap[key];
        }
        bool flag=false;
        int n=s1.length();
        
        for(int i=1;i<s1.length();i++){
            if((isScramble(s1.substr(0,i), s2.substr(n-i,i)) && 
              isScramble(s1.substr(i,n-i), s2.substr(0,n-i))) ||
              (isScramble(s1.substr(0,i),s2.substr(0,i)) && 
              isScramble(s1.substr(i,n-i),s2.substr(i,n-i)))){
                flag=true;
                break;
            }
        }
        umap[key]=flag;
        return flag;
    }
};