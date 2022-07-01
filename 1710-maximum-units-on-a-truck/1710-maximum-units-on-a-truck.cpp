class Solution {
public:
    static bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 return v1[1] > v2[1]; 
} 
    int maximumUnits(vector<vector<int>>& v, int bsize) {
        sort(v.begin(),v.end(),sortcol);
        int ans=0;
        for(auto&a:v){
            if(bsize>=a[0]){
                bsize-=a[0];
                ans=ans+(a[0]*a[1]);
            }
            else if(bsize!=0 && bsize<a[0]){
                ans = ans+(bsize)*a[1];
                bsize=0;
            }
            else{
                break;
            }
        }
        return ans;
    }
};