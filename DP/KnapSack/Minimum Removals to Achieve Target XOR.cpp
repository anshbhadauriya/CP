class Solution {
public:
int solve(int i,int xorr,vector<int>&nums,int &target,unordered_map<int,unordered_map<int,int>>&dp){

    if(i==nums.size()){
        if(xorr==target) return 0;

        return 1e9;
    }

    if(dp[i].count(xorr)) return dp[i][xorr];

    int take=solve(i+1,xorr^nums[i],nums,target,dp);
    int skip=1+solve(i+1,xorr,nums,target,dp);

    return dp[i][xorr]=min(take,skip);
}
    int minRemovals(vector<int>& nums, int target) {
    unordered_map<int,unordered_map<int,int>>dp;
     int ans=solve(0,0,nums,target,dp);

     if(ans>=1e9) return -1;

     return ans;
    }
};
