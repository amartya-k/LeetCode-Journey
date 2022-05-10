class Solution {
public:
    bool isMonotonic(vector<int>& v) {
        if(v.size()==1) return true;
        bool inc=false,dec=false;
        
        for(int i=0;i<v.size()-1;i++){
            if(v[i]<v[i+1])
                inc=true;
            else if(v[i]>v[i+1])
                dec=true;
            if(inc&&dec)
                return false;
        }
        
        return true;
    }
};