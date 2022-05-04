class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // vector<int>v;
        // v=nums;
        nums.insert(nums.begin(),nums.begin(),nums.end());
        return nums;
    }
};