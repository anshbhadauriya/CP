Same as previous but here limit is K.

class Solution {
public:
int solve(vector<int>&prices,int buy,int i,int k,vector<vector<vector<int>>>&dp){
    if(i==prices.size() or k==0){
        return 0;
    }
    if(dp[i][buy][k]!=-1){
        return dp[i][buy][k];
    }
    int profit=0;
    if(buy){
        profit=max(solve(prices,0,i+1,k,dp)-prices[i],0+solve(prices,1,i+1,k,dp));
    }
    else{
        profit=max(solve(prices,1,i+1,k-1,dp)+prices[i],solve(prices,0,i+1,k,dp));
    }
    return dp[i][buy][k]=profit;
}
    int maxProfit(int k,vector<int>& prices) {
        int i=0;
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(prices,1,i,k,dp);
    }
};
