class Solution {
public:
    int missingNumber(vector<int>& v) {
        // int n=v.size();
        // int sum = n*(n+1)/2;
        // int sum1 = accumulate(v.begin(), v.end(), 0);
        // return (sum-sum1);
        int a=v[0],b=0;
        for(int i=1;i<v.size();i++){
            a^=v[i];
            b^=i;
        }
        b^=(v.size());
        return a^b;
    }
};