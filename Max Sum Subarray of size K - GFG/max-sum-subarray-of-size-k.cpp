// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        //long mx=0,c_sum=0;
        // //calculate first window sum
        // for(int i=0;i<K;i++)
        //     c_sum+=Arr[i];
        // mx=max(mx,c_sum);
        
        // for(int i=K;i<Arr.size();i++){
        //     c_sum-=Arr[i-K];
        //     c_sum+=Arr[i];
        //     mx=max(mx,c_sum);
        // }
        // return mx;
        
        //second approach
        long mx=0,c_sum=0;
        int i=0,j=0;
        while(j<Arr.size()){
            c_sum+=Arr[j];
            if(j-i+1==K){
                mx=max(mx,c_sum);
                c_sum-=Arr[i++];
                
            }
            j++;
            
        }
        return mx;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends