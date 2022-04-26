class Solution {
public:
    int maxProfit(vector<int>& p) {
       int mf=0,cp=INT_MAX;
        for(int i=0;i<p.size();i++){
            if(cp>p[i]){
                cp=p[i];
            }
            else{
                mf=max(p[i]-cp,mf);
            }
            
        }
        return mf;
    }
};