//This will give TLE because constraints are big for backtracking so its just a TLE solution and to optimize it use unbounded knapsack

class Solution {
public:
void solve(int i,int sum,vector<int>&nums,int &target,int &count){
    if(sum>target) return;

    if(sum==target){
        count++;
        return;
    }

    if(i>=nums.size()) return;

    solve(0,sum+nums[i],nums,target,count);
    solve(i+1,sum,nums,target,count);
    
}
    int combinationSum4(vector<int>& nums, int target) {
        int count=0;
        solve(0,0,nums,target,count);
        return count;
    }
};


//Unboounded knackappraoch

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
