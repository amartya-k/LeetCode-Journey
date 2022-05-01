class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>pq;
        unordered_map<int,int>um;
        pair<int,char>p1,p2;
        p1=make_pair(0,'a');
        p2=p1;
        string t;
        for(int i=0;i<s.length();i++){
            um[s[i]]++;
        }
        // tchars=um.size();
        // cout<<tchars<<endl;
        for(auto x:um){
            pq.push(make_pair(x.second,x.first));
        }
        
        while(!pq.empty()){
            p1=pq.top();
            pq.pop();
            t.push_back(p1.second);
            
            if(!pq.empty()){
                p2=pq.top();
                pq.pop();
                t.push_back(p2.second);
                if(p2.first>1){
                    pq.push({p2.first-1,p2.second});
                }
            }
            if(p1.first>1){
                pq.push({p1.first-1,p1.second});
            }
            
        }
        
        for(int i=0;i<t.length()-1;i++){
            if(t[i]==t[i+1]) 
                return "";
        }
        
        return t;
    }
};