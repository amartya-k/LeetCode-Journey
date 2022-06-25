class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>umap;
        int ans=0;
        
        for(auto&i:s){
            umap[i]++;
        }
        
        for(auto&i:s){
            if(umap.find(i)!=umap.end()){
                if(umap[i]%2==0){
                    ans+=umap[i];
                    umap.erase(i);
                }
                else if(umap[i]>1){
                    ans+=(umap[i]-1);
                    umap[i]=1;
                }
            }
        }
        if(umap.size()>0){
            ans++;
        }
        return ans;
    }
};