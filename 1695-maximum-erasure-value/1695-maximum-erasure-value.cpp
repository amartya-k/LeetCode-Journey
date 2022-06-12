class Solution {
public:
    int maximumUniqueSubarray(vector<int>& v) {
        int m=0,csum=0,j=0;
        unordered_set<int>uset;
        
        for(int i=0,j=0;j<v.size(),i<v.size();i++){
            while(uset.find(v[i])!=uset.end()){
                uset.erase(v[j]);
                csum-=v[j];
                j++;
            }
            
            uset.insert(v[i]);
            csum+=v[i];
            m=max(csum,m);
        }
        return m;
    }
};