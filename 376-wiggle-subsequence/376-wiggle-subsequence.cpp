class Solution {
public:
    int wiggleMaxLength(vector<int>& v) {
        //first  i < i+n
        //second i>i+n
        int p=0,n=0;

        for(int i=1;i<v.size();i++){
            if(v[i-1]<v[i]){
                p=n+1;
            }
            else if(v[i-1]>v[i]){
                n=p+1;
            }
        }
        return max(p,n)+1;
    }
};