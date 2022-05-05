class Solution {
public:
    int scoreOfParentheses(string str) {
        stack<int>s;
        int i,j;
        s.push(0);
        
        for(auto c:str){
            if(c=='('){
                s.push(0);
            }
            else{
                i=s.top();
                s.pop();
                j=s.top();
                s.pop();
                s.push(j+max(2*i,1));
            }
        }
        cout<<s.size()<<endl;
        
        return s.top();
        
    }
};