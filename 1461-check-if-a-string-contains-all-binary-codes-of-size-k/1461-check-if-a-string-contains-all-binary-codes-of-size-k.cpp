class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length()<=k)
            return false;
        unordered_set<string>uset;
        unsigned long long total = 1<<k;

        for(int i=0;i<=s.length()-k;i++){
            string t=s.substr(i,k);
            
            if(uset.find(t)==uset.end()){
                uset.insert(t);
                
            }
        }

        return total==uset.size() ? true:false;
    }
};