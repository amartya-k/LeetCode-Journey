class Solution {
public:
    bool canPartition(vector<int>& v) {
        int sum=0;
        for(auto i:v){
            sum+=i;
        }
        if(sum%2!=0)
            return false;
        sum/=2;
        //create dp array
        vector<vector<bool>>dp(v.size()+1,vector<bool>(sum));
        for(int i=0;i<=v.size();i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=sum;i++){
            dp[0][i]=false;
        }
        //Actual logic
        for(int i=1;i<=v.size();i++){
            for(int j=1;j<=sum;j++){
                if(v[i-1]<=j){
                    dp[i][j]=dp[i-1][j-v[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[v.size()][sum];
    }
};