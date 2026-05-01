Recursive->

    class Solution {
public:
int solve(vector<int>&prices,int buy,int i){
    if(i==prices.size()){
        return 0;
    }
    int profit=0;
    if(buy){
        profit=max(solve(prices,0,i+1)-prices[i],0+solve(prices,1,i+1));
    }
    else{
        profit=max(solve(prices,1,i+1)+prices[i],solve(prices,0,i+1));
    }
    return profit;
}
    int maxProfit(vector<int>& prices) {
        int i=0;
        return solve(prices,1,i);
    }
};

Memoized->

class Solution {
public:
int solve(vector<int>&prices,int buy,int i,vector<vector<int>>&dp){
    if(i==prices.size()){
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
        profit=max(solve(prices,1,i+1,dp)+prices[i],solve(prices,0,i+1,dp));
    }
    return dp[i][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
        int i=0;
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return solve(prices,1,i,dp);
    }
};


Tabulation->

    class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    profit=max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);
                }
                else{
                    profit=max(prices[ind]+dp[ind+1][1],0+dp[ind+1][0]);
                }
                dp[ind][buy]=profit;
            }
        }
        return dp[0][1];
    }
};


New attempt->

class Solution {
public:

int solve(int i,int bought,vector<int>&prices, vector<vector<int>>&dp){

    if(i>=prices.size()) return 0;

    if(dp[i][bought]!=-1) return dp[i][bought];

    if(bought==0){
        int buy=-prices[i]+solve(i+1,1,prices,dp);
        int skip=solve(i+1,bought,prices,dp);

        return dp[i][bought]= max(buy,skip);
    }
    else{
        int sell=prices[i]+solve(i+1,0,prices,dp);
        int not_sell=solve(i+1,bought,prices,dp);
        
        return dp[i][bought]=max(sell,not_sell);
    }
}
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(0,0,prices,dp);
    }
};
