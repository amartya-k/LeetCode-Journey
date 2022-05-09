class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int>res;
        
        for(int i=0;i<exp.length();i++){
            if(exp[i]<'0'){
                vector<int>left=diffWaysToCompute(exp.substr(0,i));
                vector<int>right=diffWaysToCompute(exp.substr(i+1));
                for(auto i1:left){
                    for(auto i2:right){
                     switch(exp[i]){
                         case '+': res.push_back(i1+i2);
                             break;
                         case '-':res.push_back(i1-i2);
                             break;
                         case '*':res.push_back(i1*i2);
                             break;
                         default:break;
                             
                     }   
                    }
                }
                
            }
        }
        if(res.size()==0){
            res.push_back(stoi(exp));
            
        }
        return res;
    }
};
/*




*/