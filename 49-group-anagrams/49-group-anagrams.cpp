class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        //unordered_map<string,string>um1;
        string temp;
        
        unordered_map<string,vector<string>>um;
        
        for(auto s:strs){
            temp=s;
            sort(temp.begin(),temp.end());
           // um[s]=temp;
            vector<string>vs;
            auto it=um.find(temp);
            if(it!=um.end()){
                vs = um[temp];
                vs.push_back(s);
                um[temp]=vs;
            }
            else{
                vs.push_back(s);
                um[temp]=vs;
            }
        }
        for(auto i:um){
            res.push_back(i.second);
        }
        
        
        
        
        return res;
    }
};

/*
["eat","tea","tan","ate","nat","bat"]




*/