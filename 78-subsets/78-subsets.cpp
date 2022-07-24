class Solution {
public:
    vector<vector<int>> subsets(vector<int>& v) {
        // vector<vector<int>>v;
        // vector<int>a;
        // subset(0,nums,v,a);
        // return v;
        vector<vector<int>>ans;
        int n=v.size();
        for(int i=0;i<(1<<n);i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    temp.push_back(v[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
    
    // void subset(int i, vector<int>& nums, vector<vector<int>>&v,vector<int>&a){
    //     if(i>=nums.size()){
    //         //store the subset
    //         v.push_back(a);
    //         return;
    //     }
    //     //take
    //     a.push_back(nums[i]);
    //     subset(i+1,nums,v,a);
    //     //not take
    //     a.pop_back();
    //     subset(i+1,nums,v,a);
    // }
};