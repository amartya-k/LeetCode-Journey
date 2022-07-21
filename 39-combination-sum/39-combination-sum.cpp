class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        solve(0,target,a,res,temp);
        return res;
    }
    
    void solve(int idx, int sum, vector<int>& a, vector<vector<int>>&res, vector<int>&temp){
        //base
        if(idx==a.size()){
            if(sum==0){
                //store the array;
                res.push_back(temp);
            }
            return;
        }
        //take
        if(a[idx]<=sum){
            temp.push_back(a[idx]);
            solve(idx,sum-a[idx],a,res,temp);
            temp.pop_back();
        }
        
        //not take
        solve(idx+1,sum,a,res,temp);
    }
};