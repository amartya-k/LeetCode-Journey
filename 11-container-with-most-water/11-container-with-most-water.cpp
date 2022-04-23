class Solution {
public:
    int maxArea(vector<int>& v) {
        int n=v.size();
        int l=0,r=n-1,h,area=0;
        
        while(l<r){
            h=min(v[l],v[r]);
            area=max((r-l)*h,area);
            
            if(v[l]<v[r]){
                l++;
            }
            else{
                r--;
            }
            
      
          // cout<<lf<<", "<<rh<<", "<<h<<", "<<area<<endl;
        }
        return area;
    }
};