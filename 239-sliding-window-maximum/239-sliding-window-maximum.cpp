class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        list<int>v;
        int i=0,j=0;
        if(k>nums.size())
        {
            res.push_back(*max_element(nums.begin(),nums.end()));
            return res;
         }
        
        while(j<nums.size()){
            //calculations
            while(v.size()!=0 && v.back()<nums[j]){
                v.pop_back();
            }
            v.push_back(nums[j]);
            
            //Window hit
            if(j-i+1==k){
                //store ans
                res.push_back(v.front());
                
                //restore calculations
                if(nums[i]==v.front())
                    v.pop_front();
                i++;
            }
            j++;
        }
        return res;
    }
};