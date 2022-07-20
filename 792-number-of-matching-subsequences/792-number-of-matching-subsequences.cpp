class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>v(26);
        int count=0;
        //lookup table with indices
        for(int i=0;i<s.length();i++){
            v[s[i]-'a'].push_back(i);
        }
        
        for(auto&w:words){
            if(v[w[0]-'a'].size()==0){
                continue;
            }
            int cur=v[w[0]-'a'][0];
            count++;
            for(int j=1;j<w.length();j++){
                if(v[w[j]-'a'].size()==0){
                    count--;
                    break;
                }
                auto it= upper_bound(v[w[j]-'a'].begin(),v[w[j]-'a'].end(),cur);
                if(it==v[w[j]-'a'].end()){
                    count--;
                    break;
                }
                cur=*it;
            }
            
        }
        return count;
    
    }
    

};

/*
a:0
b:1
c:
*/