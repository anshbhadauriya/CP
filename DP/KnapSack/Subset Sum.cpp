Recusrive->


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




Memoized->

  class Solution {
  public:
  bool solve(vector<int>&arr,int sum,int i,vector<vector<int>>&dp){
      if(sum==0){
          return true;
      }
      if(dp[i][sum]!=-1){
          return dp[i][sum];
      }
       if(i==arr.size()) return false; 
       
      if(arr[i]<=sum){
          return dp[i][sum]=solve(arr,sum-arr[i],i+1,dp) || solve(arr,sum,i+1,dp);
      }
      else {
            return dp[i][sum]=solve(arr,sum,i+1,dp);
        }
  }
    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));
       return solve(arr,sum,0,dp);
        
    }
};
