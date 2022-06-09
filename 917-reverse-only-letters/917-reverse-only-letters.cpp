class Solution {
public:
    string reverseOnlyLetters(string s) {
        int j=s.length()-1,i=0;
        while(i<=j){
            if(isalpha(s[i]) && isalpha(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(!isalpha(s[i])){
                i++;
            }
            else if(!isalpha(s[j])){
                j--;
            }
        }
        return s;
    }
};