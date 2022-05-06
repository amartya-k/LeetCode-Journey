class Solution {
public:
    string removeOuterParentheses(string str) {
        int depth=0,pdepth=0;
        string res="";
        for(int i=0;i<str.length();i++){
            pdepth=depth;
            if(str[i]=='('){
                depth++;
            }
            else{
                depth--;}
            if(i!=0 &&depth!=0 && pdepth!=0){
                    //res+=prev;
                  res+=str[i];
             }
            
      }
        return res;
    }
};

/*
 (()())(())
 1212101210
 
 "(()())(())(()(()))"
  121210121012123210
 
 (()(()))
 1212311
 
*/