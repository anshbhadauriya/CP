class Solution {
  public:
  bool solve(vector<int>&arr,int sum,int i){
      if(sum==0){
          return true;
      }
       if(i==arr.size()) return false; 
       
      if(arr[i]<=sum){
          return solve(arr,sum-arr[i],i+1) || solve(arr,sum,i+1);
      }
      else {
            return solve(arr,sum,i+1);
        }
  }
    bool isSubsetSum(vector<int>& arr, int sum) {
       return solve(arr,sum,0);
        
    }
};