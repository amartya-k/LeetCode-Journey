class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        vector<int>uset;
        vector<vector<int>>ans;
        sort(a.begin(),a.end());
        comb(0,target,a,uset,ans);
        return ans;
    }
    
    void comb(int idx,int sum, vector<int>& a, vector<int>&uset,vector<vector<int>>&ans){
        //base
        if(sum==0){
            ans.push_back(uset);
            return;
        }
  
        //take
        for(int i=idx;i<a.size();i++){
            if(i>idx && a[i]==a[i-1]) continue;
            
            if(a[i]>sum) break;
                uset.push_back(a[i]);
                comb(i+1,sum-a[i],a,uset,ans);
                uset.pop_back();
        }
    }
};