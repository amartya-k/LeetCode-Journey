class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>umap;
        int ans=0;
        for(auto i:nums)
            umap[i]++;
        
        for(auto i:umap){
            if(i.second>nums.size()/2){
                ans=i.first;
                break;
            }
        }
        return ans;
    }
};