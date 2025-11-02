Recursive->

  class Solution {
public:
int solve(vector<int>&prices,int buy,int i,int cap){
    if(i==prices.size() or cap==0){
        return 0;
    }
    int profit=0;
    if(buy){
        profit=max(solve(prices,0,i+1,cap)-prices[i],0+solve(prices,1,i+1,cap));
    }
    else{
        profit=max(solve(prices,1,i+1,cap-1)+prices[i],solve(prices,0,i+1,cap));
    }
    return profit;
}
    int maxProfit(vector<int>& prices) {
        int i=0;
        return solve(prices,1,i,2);
    }
};

Memoized->

  class Solution {
public:
int solve(vector<int>&prices,int buy,int i,int cap,vector<vector<vector<int>>>&dp){
    if(i==prices.size() or cap==0){
        return 0;
    }
    if(dp[i][buy][cap]!=-1){
        return dp[i][buy][cap];
    }
    int profit=0;
    if(buy){
        profit=max(solve(prices,0,i+1,cap,dp)-prices[i],0+solve(prices,1,i+1,cap,dp));
    }
    else{
        profit=max(solve(prices,1,i+1,cap-1,dp)+prices[i],solve(prices,0,i+1,cap,dp));
    }
    return dp[i][buy][cap]=profit;
}
    int maxProfit(vector<int>& prices) {
        int i=0;
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3, -1)));
        return solve(prices,1,i,2,dp);
    }
};

Tabulation->

  class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++) {
                for(int cap=1;cap<=2;cap++) {  
                    int profit=0;
                    if(buy){
                        profit=max(-prices[idx]+dp[idx+1][0][cap],0+dp[idx+1][1][cap]);
                    } else {
                        profit=max(prices[idx]+dp[idx+1][1][cap-1],0+dp[idx+1][0][cap]);
                    }
                    dp[idx][buy][cap]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
};
