// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int h=n,l=1,mid;
        while(l<=h){
            mid=l+(h-l)/2;
            if(isBadVersion(mid)==false){
                l=mid+1;
            }
            else if(isBadVersion(mid) && isBadVersion(mid-1)){
                h=mid-1;
            }
            else{
                break;
            }
        }
        return mid;
    }
};

/*
F,F,F,F,T,T,T

*/