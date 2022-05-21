class Solution {
public:
    int findTargetSumWays(vector<int>& v, int tar) {
        int sum=0,sum2=0,n=v.size();
        for(auto i:v){
            sum+=i;
        }
        //condition to check if target & sum are odd and even or vise versa
        if((sum+tar)%2 !=0 || sum<abs(tar)){
            return 0;
        }
        //cout<<"sum1="<<sum<<endl;
        sum=abs((sum-tar)/2);
        //cout<<"sum2="<<sum<<endl;
        // vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        vector<int>dp1(sum+1,0);
        vector<int>dp2(sum+1,0);
        
        
        //initialise dp array
        dp1[0]=1;
        dp2[0]=1;
        // for(int i=0;i<n+1;i++){
        //     dp[i][0]=1;
        // }
        
        //main logic
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(v[i-1]<=j){
                    // dp[i][j] = dp[i-1][j] + dp[i-1][j-v[i-1]];  
                    dp2[j] = dp1[j] + dp1[j-v[i-1]];
                }
                else{
                    // dp[i][j] = dp[i-1][j];
                    dp2[j] = dp1[j];
                }
            }
            dp1=dp2;
            
        }
        return dp1[sum];
        
    }
};
/*
s1-s2=target
s1+s2=total

7+1=8 even
7-1 = 6 even

7-2= 5 odd
7+2 = 5 odd


s1-s2=1000
s1+s2=958
=> -s2 = 42/2 or 21

*/