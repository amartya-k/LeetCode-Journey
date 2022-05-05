class Solution {
public:
    // int scoreOfParentheses(string str) {
    //     stack<int>s;
    //     s.push(0);
    //     for(auto c:str){
    //         if(c=='(')
    //             s.push(0);
    //         else{
    //             int t=s.top();
    //             s.pop();
    //             if(t==0){
    //                 s.top()+=1;
    //             }
    //             else{
    //                 s.top()+=(2*t);
    //             }
    //         }
    //     }
    //     return s.top();
    // }
        int scoreOfParentheses(string str) {
            int depth=0,sc=0,prev;
            for(auto c:str){
                if(c=='('){
                    depth++;
                }
                else{
                    depth--;
                    if(prev=='(')
                        sc+=1<<depth;
                }
                prev=c;
            }
        return sc;
        
        }

};
