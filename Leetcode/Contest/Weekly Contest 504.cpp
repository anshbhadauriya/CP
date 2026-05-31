Q1->
  class Solution {
public:
    int digitFrequencyScore(int n) {

        int ele=n;

        unordered_map<int,int>mp;

        while(ele>0){

            int r=ele%10;
            mp[r]++;

            ele=ele/10;
            
        }

        int ans=0;

        for(auto x:mp){
            ans+=(x.first*x.second);
        }

        return ans;
        
    }
};

Q2->

  int const MAXN = 1000, MAXB = 1500;
int dp[MAXN + 1][MAXB + 1][2];

class Solution {
public:

    int solve(int i, vector<vector<int>>& items, int budget,
              bool first_buy, vector<int>& free_count) {

        if (i >= items.size()) return 0;

        if (dp[i][budget][first_buy] != -1)
            return dp[i][budget][first_buy];

        int skip = solve(i + 1, items, budget, true, free_count);

        int take = 0;
        int price = items[i][1];

        if (budget >= price) {

            int curr_gain;

            if (first_buy)
                curr_gain = 1 + free_count[i];
            else
                curr_gain = 1;

            take = curr_gain +
                   solve(i, items, budget - price, false, free_count);
        }

        return dp[i][budget][first_buy] = max(skip, take);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        memset(dp, -1, sizeof(dp));

        int n = items.size();

        vector<int> free_count(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                
                if (i!=j and items[j][0] % items[i][0] == 0)
                    free_count[i]++;
            }
        }

        return solve(0, items, budget, true, free_count);
    }
};
