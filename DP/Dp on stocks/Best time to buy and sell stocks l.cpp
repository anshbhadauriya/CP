class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int minimum=prices[0],maximum=0;
     for(int i=1;i<prices.size();i++){
        int diff=prices[i]-minimum;
        maximum=max(maximum,diff);

        minimum=min(minimum,prices[i]);
     }
     return maximum;   
    }
};


Recursive->
(not good appraoch for this ques)
    class Solution {
public:

int solve(int i, int bought, int transactions, vector<int>& prices,vector<vector<vector<int>>>&dp){

    if(i >= prices.size()) return 0;

    // already done 1 transaction so stop
    if(transactions == 1) return 0;

    if(dp[i][bought][transactions]!=-1) return dp[i][bought][transactions]; 

    

    if(bought == 0){
        // buy or skip
        int buy = -prices[i] + solve(i+1, 1, transactions, prices,dp);
        int skip = solve(i+1, 0, transactions, prices,dp);

        return dp[i][bought][transactions]=max(buy, skip);
    }
    else{
        // sell or hold
        int sell = prices[i] + solve(i+1, 0, 1, prices,dp);
        int hold = solve(i+1, 1, transactions, prices,dp);

        
        return dp[i][bought][transactions]=max(sell, hold);
    }

    
}

int maxProfit(vector<int>& prices) {

    vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
    return solve(0, 0, 0, prices,dp);
}
};
