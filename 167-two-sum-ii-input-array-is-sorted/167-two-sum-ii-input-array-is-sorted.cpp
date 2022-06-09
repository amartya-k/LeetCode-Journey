class Solution {
public:
//     vector<int> twoSum(vector<int>& v, int t) {
//         unordered_map<int,int>umap;
//         int idx1=0,idx2=0;
        
//         for(int i=0;i<v.size();i++){
//             umap[v[i]]=i;
//             //cout<<umap[t-v[i]]<<" "<<t-v[i]<<endl;
//         }
        
//         for(int i=0;i<v.size();i++){
//             if(umap.find(t-v[i])!=umap.end() && i!=umap[t-v[i]]){
//                 idx1=i+1;
//                 idx2=umap[t-v[i]]+1;
//                // cout<<t-v[i]<<" --"<<umap[t-v[i]]<<endl;
//                 break;
//             }
//         }
//         if((idx1>idx2)) return {idx2,idx1};
//         return {idx1,idx2};
//     }
//     vector<int> twoSum(vector<int>& v, int t) {
//         int x=0,y=0,temp;
        
//         for(int i=0;i<v.size()-1;i++){
//             temp=binarys(i+1,v.size()-1,t-v[i],v);
//             if(temp!=-1 ){
//                 x=temp+1;
//                 y=i+1;
//                 break;
//             }
//         }
//         if(x>y) return {y,x};
//     return {x,y};
//     }
    
//     int binarys(int l,int h, int key,vector<int>& v){
//         int m;
//         while(l<=h){
//             m=l+(h-l)/2;
//             if(key>v[m]){
//                 l=m+1;
//             }
//             else if(key<v[m]){
//                 h=m-1;
//             }
//             else{
//                 return m;
//             }
//         }
//         return -1;
//     }
     vector<int> twoSum(vector<int>& v, int t) {
         int l=0,h=v.size()-1,sum;
         while(l<h){
             sum=v[l]+v[h];
             if(sum==t) return {l+1,h+1};
             else if(sum<t)
                 l++;
             else
                 h--;
         }
         return {};
     }
};


















