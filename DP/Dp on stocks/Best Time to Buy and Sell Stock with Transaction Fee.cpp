It is same but there is a transition fees after each stock you sell!
(you can either put fee while buying or selling)
  class Solution {
public:
int solve(vector<int>& prices,int i,int buy,int fee,vector<vector<int>>&dp){
    if(i>=prices.size()){
        return 0;
    }
    if(dp[i][buy]!=-1){
        return dp[i][buy];
    }
    int profit=0;
    if(buy){
        profit=max(-prices[i]+solve(prices,i+1,0,fee,dp),solve(prices,i+1,1,fee,dp));
    }
    else{
        profit=max(prices[i]-fee+solve(prices,i+1,1,fee,dp),solve(prices,i+1,0,fee,dp));
    }
    return dp[i][buy]=profit;


}
    int maxProfit(vector<int>& prices, int fee) {
        int i=0;
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return solve(prices,i,1,fee,dp);
    }
};
