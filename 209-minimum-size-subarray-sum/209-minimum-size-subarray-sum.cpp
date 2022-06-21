class Solution {
public:
    int minSubArrayLen(int target, vector<int>& v) {
        int i=0,j=0,sum=0,mx=INT_MAX;
        
        while(j<v.size()){
            //cals
            sum+=v[j];
            
        //window hit
            //modify sum
            while(sum>=target){
                mx=min(j-i+1,mx);
                sum-=v[i++];
            }
            
            j++;
        }
        if(mx==INT_MAX)
            return 0;
        return mx;
    }
};

/*
7
[2,3,1,2,4,3]

2,3,1,2 : sum=8
3,1,2,4 : sum=10

2,4,3:


*/