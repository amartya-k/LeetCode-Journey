class Solution {
public:
    int ham(int n){
        int cnt=0;
        while(n){
            cnt++;
            n=n&(n-1);
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int>v(n+1);
        
        for(int i=0;i<n+1;i++){
            v[i]=ham(i);
        }
        return v;
    }
};