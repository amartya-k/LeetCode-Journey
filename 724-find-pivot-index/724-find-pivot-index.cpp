class Solution {
public:
    int pivotIndex(vector<int>& v) {
        int total=0,lsum=0,rsum=0;
        
        for(int i=0;i<v.size();i++){
            total+=v[i];
        }
        for(int i=0;i<v.size();i++){
            rsum=total-lsum-v[i];
            if(lsum==rsum){
                return i;
            }
            lsum+=v[i];
        }
        return -1;
    }
};
/*
numss= [1,7,3,6,5,6]
p=0,1,8,11,17,22,28

p[3]=11
p[6]-p[3]-nums[3]
28-11-6=

nums=[2,1,-1]
P= 0,2,3,2
p[0]=0
2-0-2=0
*/