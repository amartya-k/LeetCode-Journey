class Solution {
public:
    int maxSubArray(vector<int>& v) {
       int m=INT_MIN,csum=0;
        
        for(int i=0;i<v.size();i++){
            csum+=v[i];
            m=max(m,csum);
            csum= csum<0?0:csum;
        }
        return m;
    }
};

/*
[5,4,-1,7,8]
m=inf_min, s=0

i=0, s=5, m=5
i=1, s=9, m=9
i=2, s=8, m=9
i=3, s=15, m=15
i=4, s=23, m=23



*/