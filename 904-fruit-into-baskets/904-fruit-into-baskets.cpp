class Solution {
public:
    int totalFruit(vector<int>& v) {
        int i=0,j=0,k=2,mx=0;
        unordered_map<int,int>umap;
        
        while(j<v.size()){
            umap[v[j]]++;
            
            while(i<=j && umap.size()>k){
                //remove
                umap[v[i]]--;
                if(umap[v[i]]==0){
                    umap.erase(v[i]);
                }
                i++;
            }
           
            mx=max(j-i+1,mx);
            j++;
        }
        return mx;
    }
};
/*
2:4
3:1


*/