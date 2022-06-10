class Solution {
public:
    int maxProfit(vector<int>& v) {
       int m=0,cp=10001;
        
        for(int i=0;i<v.size();i++){
            if(cp>v[i]){
                cp=v[i];
            }
            m=max(m,v[i]-cp);
        }
        return m;
    }
};