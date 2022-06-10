class Solution {
public:
    void sortColors(vector<int>& v) {
        for(int i=0;i<v.size();i++){
            for(int j=v.size()-1;j>i;j--){
                if(v[j-1]>v[j]){
                    swap(v[j-1],v[j]);
                }
            }
        }
    }
};