#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
long long solve(vector<int>& dice, int n, int i, vector<vector<long long>>& dp) {    
    if(n == 0) return 1;      
    if(i == dice.size()) return 0; 

    if(dp[i][n] != -1) return dp[i][n];

    long long ways = 0;
    if(dice[i] <= n) {
        ways = (ways + solve(dice, n - dice[i], 0, dp)) % MOD; 
    }
    ways = (ways + solve(dice, n, i + 1, dp)) % MOD; 

    return dp[i][n] = ways;
}

int main() {
    int n;
    cin >> n;
    vector<int> dice{1,2,3,4,5,6};
    vector<vector<long long>> dp(6, vector<long long>(n + 1, -1));

    cout << solve(dice, n, 0, dp) << endl; 
    return 0;
}
