recursive->

class Solution {
public:
int solve(int idx,int prev_idx,vector<int>&nums,int n){
    if(idx==n){
        return 0;
    }
    int len=0+solve(idx+1,prev_idx,nums,n);

    if(prev_idx==-1 or nums[idx]>nums[prev_idx]){
        len=max(len,1+solve(idx+1,idx,nums,n));
    }
    return len;
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        return solve(0,-1,nums,n);
    }
};


memoized->


class Solution {
public:
int solve(int idx,int prev_idx,vector<int>&nums,int n,vector<vector<int>>&dp){
    if(idx==n){
        return 0;
    }
    if(dp[idx][prev_idx+1]!=-1){
        return dp[idx][prev_idx+1];
    }
    int len=0+solve(idx+1,prev_idx,nums,n,dp);

    if(prev_idx==-1 or nums[idx]>nums[prev_idx]){
        len=max(len,1+solve(idx+1,idx,nums,n,dp));
    }
    return dp[idx][prev_idx+1]=len;
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,n,dp);
    }

};

tabulation->

    class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int ind=n-1;ind>=0;ind--){
            for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--) {

                int len=dp[ind+1][prev_ind+1];

                if(prev_ind==-1 || nums[ind]>nums[prev_ind]) {
                    len=max(len,1+dp[ind+1][ind+1]);
                }

                dp[ind][prev_ind+1]=len;
            }
        }

        return dp[0][0];
    }
};
