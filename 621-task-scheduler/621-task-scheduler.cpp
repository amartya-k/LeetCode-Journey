class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>um;
        priority_queue<int>pq;
        
        int ans=0,cnt;
        for(auto c:tasks)
            um[c]++;
        
        for(auto i:um){
            pq.push(i.second);
        }
        
        while(!pq.empty()){
            vector<int>v;
            cnt=0;
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                    v.push_back(pq.top()-1);
                    pq.pop();
                    cnt++;
                }
                
            }
            
            for(auto i:v){
                if(i)
                pq.push(i);
        }
            ans+=pq.empty()?cnt:n+1;
            
        }
        return ans;
    }
};