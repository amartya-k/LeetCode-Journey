class Solution {
public:
    void nextPermutation(vector<int>& v) {
        bool flag=false;
        int pivot=-1;
        for(int i=v.size()-1;i>=1;i--){
            if(v[i-1]<v[i]){
                pivot=i-1;
                flag=true;
                break;
            }
        }
        //find element just greater than pivot index
        if(flag){
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]>v[pivot]){
                swap(v[pivot],v[i]);
                break;
            }
        }
        }
        sort(v.begin()+pivot+1,v.end());
    }
};