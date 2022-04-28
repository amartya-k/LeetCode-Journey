class Solution {
public:
    static bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[1] < v2[1];
}
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),sortcol);
        
        int arrows=1,end=p[0][1];
        for(int i=1;i<p.size();i++){
            if(p[i][0]>end){
                arrows+=1;
                end=p[i][1];
            }
        }
        return arrows;
    }
};
/*

1,6
2,8
7,12
10,16

1,2
2,3
3,4
4,5


*/