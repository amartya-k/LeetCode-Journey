class Solution {
public:
    int missingNumber(vector<int>& v) {
        int n=v.size();
        int sum = n*(n+1)/2;
        int sum1 = accumulate(v.begin(), v.end(), 0);
        return (sum-sum1);
    }
};