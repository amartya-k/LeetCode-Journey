class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, n = nums.size();
        for (int i : nums) sum += i;
        int target = sum - x;
        int curr_sum = 0, max_len = 0;
        int start_idx = 0;
        bool found = false;
        for (int end_idx = 0; end_idx < n; end_idx++) {
            curr_sum += nums[end_idx];
            while (start_idx <= end_idx && curr_sum > target) {
                curr_sum -= nums[start_idx];
                start_idx += 1;
            }
            if (curr_sum == target) {
                found = true;
                max_len = max(max_len, end_idx - start_idx + 1);
            }
        }
        return found ? n - max_len : -1;
    }
};
/*
[1,1,4,2,3] 
max_sum=11, update-> max_sum-=x or 11-5=6 
in maximum subarray->take mx no. of elements
Kadane's algo:
csum+=v[i];
m=max(m,csum);
csum= csum<0?0:csum;


*/