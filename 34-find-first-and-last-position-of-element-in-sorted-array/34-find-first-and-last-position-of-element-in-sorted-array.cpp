class Solution {
public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         if(nums.size()==0) return {-1,-1};
//         int l=0,h=nums.size()-1,m;
//         vector<int>r;
        
//         while(l<h){
//             m=l+(h-l)/2;
//             if(nums[m]<target)
//                 l=m+1;
//             else
//                 h=m;
//         }
//         if(nums[l]!=target)
//              return {-1,-1};
//         else
//             r.push_back(l);
//         h=l;

//         while(l<nums.size() && nums[h]==nums[l]){
//             l++;
//         }
        
//         r.push_back(l-1);
//         return r;
//     }
    vector<int> searchRange(vector<int>& a, int t) {
        if(a.size()==0) return {-1,-1};
        int l=0,h=a.size()-1,m;
        vector<int>r(2,-1);
        
        while(l<h){
            m=(l+h)/2;
            if(t>a[m])
                l=m+1;
            else
                h=m;
        }
       // cout<<l<<","<<m;
        if(a[l]!=t)
             return r;
        else
            r[0]=l;
        
        h=a.size()-1;
        while(l<h){
            m=(l+h+1)/2;
            if(a[m]>t){
                h=m-1;
            }
            else{
                l=m;
            }
        }
       r[1]=l;
       return r;
    }
};

/*
    while (i < j)
    {
        int mid = (i + j) /2;
        if (A[mid] < target) i = mid + 1;
        else j = mid;
    }
    if (A[i]!=target) return ret;
    else ret[0] = i;
*/