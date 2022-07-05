class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        unordered_set<int> s(v.begin(), v.end());
        //ALGO: check for left neighbour presence
        //If left neighbour absent, check next elements
        //else iterate
        int sum=0,cur;
        
        for(auto&i:v){
            if(s.find(i-1)==s.end()){
                int start=i;
                cur=0;
                while(s.find(start)!=s.end()){
                    cur+=1;
                    start++;
                }
                sum=max(cur,sum);
            }
        }
        return sum;
    }
};