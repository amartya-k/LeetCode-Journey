class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& m) {
        int r=0,c=0;
        vector<vector<int>>res;
        for(c=0;c<m[0].size();c++){
            vector<int>temp;
            
            for(r=0;r<m.size();r++){
                temp.push_back(m[r][c]);
            }
            res.push_back(temp);
        }
        return res;
    }
};