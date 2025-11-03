Here when you sell the stock just do i+2 because buying just after selling is not  allowed in this question
class Solution {
public:
int solve(vector<int>&prices,int buy,int i,vector<vector<int>>&dp){
    if(i>=prices.size()){
        return 0;
    }
    if(dp[i][buy]!=-1){
        return dp[i][buy];
    }
    int profit=0;
    if(buy){
        profit=max(solve(prices,0,i+1,dp)-prices[i],0+solve(prices,1,i+1,dp));
    }
    else{
        profit=max(solve(prices,1,i+2,dp)+prices[i],solve(prices,0,i+1,dp));
    }
    return dp[i][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
        int i=0;
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return solve(prices,1,i,dp);
    }
};
