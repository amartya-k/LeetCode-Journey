class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>umap;
        int idx1=0,idx2=0;
        
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]=i;
            }
        for(int i=0;i<nums.size();i++){
            if(umap.find(target-nums[i])!=umap.end() && umap[target-nums[i]]!=i){
                idx1=umap[target-nums[i]];
                idx2=i;
                break;
            }
        }
        return {idx1,idx2};
    }
};