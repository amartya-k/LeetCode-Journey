class Solution {
public:
    int majorityElement(vector<int>& v) {
//A Linear Time Majority Vote Algorithm (ut austin)
        int maj=INT_MIN,count=0;
        
        for(int i=0;i<v.size();i++){
            if(count==0){
                maj=v[i];
            }
            
            if(v[i]==maj){
                count++;
            }
            else{
                count--;
            }
            
        }
        return maj;
    }
};