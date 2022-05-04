class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>v;
        v=nums;
        v.insert(v.begin(),nums.begin(),nums.end());
        return v;
    }
};