class Solution {
  public:
  bool solve(int i,int curr_sum,vector<int>&arr,int sum){
       
       if(curr_sum==sum){
          return true;
      }
      
      if(i>=arr.size()){
          return false;
      }
      if(curr_sum>sum) return false;
      
      return solve(i+1,curr_sum+arr[i],arr,sum) or 
      solve(i+1,curr_sum,arr,sum);
  }
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        return solve(0,0,arr,sum);
        
    }
};
