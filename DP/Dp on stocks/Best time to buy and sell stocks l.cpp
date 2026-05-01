class Solution {
public:

/*

Har point me bechne ki try kro lekin
Agr kisi point me bech rhe ho so uske piche ke minimum track kro kyuki that will give max profit

*/
    int maxProfit(vector<int>& prices) {

       int minimum=prices.front(),maximum=0;

        for(int i=1;i<prices.size();i++){

            int bought=minimum;

            int sell=prices[i];

            int profit=sell-bought;

            maximum=max(maximum,profit);   //maximum profit

            minimum=min(minimum,prices[i]);   //new bought 
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
