class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        int df1=(hc[0]> (h-hc[hc.size()-1]))?hc[0] : h-hc[hc.size()-1];
        int df2=(vc[0]> (w-vc[vc.size()-1]))?vc[0] : w-vc[vc.size()-1];
        long int m= 1000000007;
        for(int i=0;i<hc.size()-1;i++){
            df1=max(hc[i+1]-hc[i],(int)df1);
        }
        for(int i=0;i<vc.size()-1;i++){
            df2=max(vc[i+1]-vc[i],(int)df2);
        }
        return ((df1%m)*(df2%m))%m ;
    }
};