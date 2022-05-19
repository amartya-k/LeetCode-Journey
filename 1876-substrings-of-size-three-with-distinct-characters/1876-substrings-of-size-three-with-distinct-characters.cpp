class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.length()<3)
            return 0;
        
        string t=s.substr(0,3);
        t[2]=t[1]; //xyz = *xy
        t[1]=t[0];
        int count=0;
        
        for(int i=2;i<s.length();i++){
            //cout<<t<<endl;
            t.erase(0,1);
            t.push_back(s[i]);
            
            if(t[0]!=t[1] && t[1]!=t[2] && t[0]!=t[2]){
                count++;
            }
        }
        return count;
    }
};