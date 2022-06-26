class Solution {
public:
    int maxProfit(vector<int>& v) {
        int cp=INT_MAX,profit=0;
        
        for(int i=0;i<v.size();i++){
            if(v[i]<cp){
                cp=v[i];
            }
            else{
                profit=max(profit,v[i]-cp);
            }
            //cout<<cp<<endl;
        }
        return profit;
    }
};