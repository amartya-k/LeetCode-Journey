class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        if(nums.size()==1 && nums[0]==x)
            return 1;
        int sum=0, mx=INT_MIN,t_sum=0,k=0,i=0,j=0;
        
        for(int i=0;i<nums.size();i++){
            t_sum+=nums[i];
        }
        //cout<<"total="<<t_sum<<endl;
        //sum of the maximum subarray
        k=t_sum-x;
        if(k<0)
            return -1;
        //apply sliding window 
        while(j<nums.size()){
            sum+=nums[j];
            while(i<nums.size() && sum>k){
                sum-=nums[i++]; //slide the window
            }
            if(sum==k){
                //cout<<"i,j="<<i<<", "<<j<<endl;
                mx=max(mx,j-i+1);
            }
            j++;
        }
        return mx==INT_MIN?-1:nums.size()-mx;
    }
};
