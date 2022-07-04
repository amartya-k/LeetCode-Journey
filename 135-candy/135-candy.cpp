class Solution {
public:
    int candy(vector<int>& r) {
        vector<int>l(r.size(),1);
        vector<int>h(r.size(),1);
        int s=0;
        //left
        for(int i=1;i<r.size();i++){
            if(r[i]>r[i-1]){
                l[i]=l[i-1]+1;
            }
        }
        //right
        for(int i=r.size()-2;i>=0;i--){
            if(r[i]>r[i+1]){
                h[i]=h[i+1]+1;
            }
        }
        for(int i=0;i<r.size();i++){
            //cout<<l[i]<<","<<h[i]<<endl;
            s= s+ max(l[i],h[i]);
        }
        return s;
    }
};

/*
1,1,2
2,1,1
*/