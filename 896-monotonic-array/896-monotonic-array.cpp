class Solution {
public:
    bool isMonotonic(vector<int>& v) {
        if(v.size()==1) return true;
        bool inc=true;
        
        for(int i=0;i<v.size()-1;i++){
            if(v[i]>v[i+1]){
                inc=false;
                break;
            }
        }
        if(!inc){
            for(int i=0;i<v.size()-1;i++){
            if(v[i]<v[i+1]){
                return false;
            }
        }
        }
        
        return true;
    }
};