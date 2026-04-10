class Solution {
public:

using ll=long long;
int n;


ll solve(int i,vector<int>&nums,int skip,vector<vector<ll>>&dp){
    if(i>=nums.size()-1){
        return 0;
    }
    if(dp[i][skip]!=-1) return dp[i][skip];

    ll take1=LLONG_MAX,take2=LLONG_MAX;
     take1=max(0,max(nums[i+1],nums[i-1])+1-nums[i])+solve(i+2,nums,skip,dp);
    if(!skip){
     take2=max(0,max(nums[i+1],nums[i-1])+1-nums[i])+solve(i+3,nums,skip+1,dp);  //skip 
    }

    return dp[i][skip]=min(take1,take2);

}
    long long minIncrease(vector<int>& nums) {

        //nums = [1, 100, 1, 1, 100, 1]
        //index:   0   1   2   3   4   5  

        //even idx cost-> 100
        //odd idx cost-> 100
        //but in actual cost should be 0

        //if nums size is odd then cost is always going to be fixed

        //in case of even we can take adj but we can skip elements as well

         n=nums.size();


        if(n%2!=0){  //agr odd hai
        long long cost=0;
        for(int i=1;i<n-1;i+=2){
            cost+=max(0,max(nums[i+1],nums[i-1])+1-nums[i]);
        }

        return cost;


        }
        vector<vector<ll>>dp(n,vector<ll>(2,-1));


        return min(solve(1,nums,0,dp),solve(2,nums,1,dp));

    }
};
