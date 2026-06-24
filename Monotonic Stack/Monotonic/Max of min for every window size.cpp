class Solution {
  public:
  /*
  Idea of brute force is
  
  sare subarray generate kro aur unka minimum track kro
  
  jo bhi subrray ka size ho usska maximum ek vector me store kro
  */
    vector<int> maxOfMins(vector<int>& arr) {
        
        
        //brute force
        
        int n=arr.size();
        
        vector<int>temp(n+1,0);  //it will store maximum of minimum of all subarray length
        
        for(int i=0;i<n;i++){
            int minimum=INT_MAX;
            for(int j=i;j<n;j++){
                
                minimum=min(minimum,arr[j]);
                
                int size=j-i+1;
                
                if(temp[size]==0){
                    temp[size]=minimum;
                }
                else temp[size]=max(temp[size],minimum);
                
            }
        }
        
        temp.erase(temp.begin());
        
        return temp;
        
    }
};
