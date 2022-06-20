class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>umap;
        int i=0,j=0,mx=0,sum=0;
        
        while(j<s.length()){
            //cals
            umap[s[j]]++;
           
            //if dubplicates,remove it
            while(i<=j && umap[s[j]]>1){
                umap[s[i]]--;
                i++;
            }
            
            //if window hit
            mx=max(j-i+1,mx);
            j++;
        }
        return mx;
    }
};

