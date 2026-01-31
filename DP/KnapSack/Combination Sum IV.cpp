//Unbounded knapsack

class Solution {
public:
    int n;
    int dp[1001][201];
    int solve(vector<int>& nums, int sum, int target, int idx) {
        if(sum==target) return 1;
        if(sum>target or idx>=n) return 0;

        if(dp[sum][idx]!=-1) return dp[sum][idx];

       

        return dp[sum][idx]=solve(nums,sum+nums[idx],target,0)+solve(nums,sum,target,idx+1);
        //unbounded knapsack hai
    }

    int combinationSum4(vector<int>& nums, int target) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,target, 0);
    }
};
