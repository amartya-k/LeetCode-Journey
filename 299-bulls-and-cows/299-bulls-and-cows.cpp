class Solution {
public:
    string getHint(string s, string g) {
        unordered_map<char,int>umap;
        int bull=0,cow=0;
        
        for(int i=0;i<g.length();i++){
            if(s[i]==g[i]){
                bull++;
            }
            else
                umap[s[i]]++;
        }
        
        for(int i=0;i<g.length();i++){
            if(s[i]!=g[i] && umap.find(g[i])!=umap.end() && umap[g[i]]>0){
                umap[g[i]]--;
                cow++;
            }
        }
        return to_string(bull)+"A"+to_string(cow)+"B";
    }
};