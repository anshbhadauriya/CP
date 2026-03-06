class Solution {
public:
int minimum=INT_MAX;

int solve(int i,vector<int>&nums,vector<int>&dp){

    if(i>=nums.size()-1){
        return 0;
    }
    if(dp[i]!=-1) return dp[i];

    if(nums[i]==0) return INT_MAX;

    int ans=INT_MAX;
    for(int j=1;j<=nums[i];j++){

       int res = solve(i+j, nums, dp);

            if(res != INT_MAX){
                ans = min(ans, 1 + res);
            }
           
    }
    return dp[i]=ans;

   
}
    int jump(vector<int>& nums) {
        int n=nums.size();
         vector<int>dp(n+1,-1);
         return solve(0,nums,dp);
         
    }
};