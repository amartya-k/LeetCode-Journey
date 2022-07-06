class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int>umap;
        int sum=0;
        for(auto&i:nums)
            umap[i]++;
        
        for(auto&i:nums){
            if(umap[i]==1)
                sum+=i;
        }
        return sum;
    }
};