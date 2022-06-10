class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uset;
        int substring_lenght=0;
        char key;
        int j=0,i=0;
        while(i<s.length()){
            key=s[i];
            if(uset.find(key) == uset.end()){
                uset.insert(key);
                i++;
                substring_lenght = max(substring_lenght, (i-j));
                
            }
            else{
                uset.erase(s[j++]);
            }
        }
        return substring_lenght;
    }
};

