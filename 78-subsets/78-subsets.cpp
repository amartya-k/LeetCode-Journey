class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>a;
        subset(0,nums,v,a);
        return v;
    }
    
    void subset(int i, vector<int>& nums, vector<vector<int>>&v,vector<int>&a){
        if(i>=nums.size()){
            //store the subset
            v.push_back(a);
            return;
        }
        //take
        a.push_back(nums[i]);
        subset(i+1,nums,v,a);
        //not take
        a.pop_back();
        subset(i+1,nums,v,a);
    }
};