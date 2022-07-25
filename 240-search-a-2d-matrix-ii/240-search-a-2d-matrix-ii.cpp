class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int row=m.size(),col=m[0].size();
        bool ans=false;
        for(int i=0;i<row;i++){
            if(t<=m[i][col-1]){
                cout<<m[i][col-1]<<endl;
                ans=binary_search(m[i].begin(),m[i].end(),t);
                if(ans) break;
            }
            
        }
        return ans;
    }
};