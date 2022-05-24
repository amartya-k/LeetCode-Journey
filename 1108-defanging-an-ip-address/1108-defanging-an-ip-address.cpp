class Solution {
public:
    string defangIPaddr(string a) {
        string s="";
        
        for(int i=0;i<a.length();i++){
            if(a[i]=='.'){
                //s.push_back("[.]");
                s+="[.]";
            }
            else{
                s.push_back(a[i]);
            }
        }
        return s;
    }
};