Recursive->

int MCM(int i, int j, vector<int>& arr) {

    if (i == j) return 0;

    int mini = INT_MAX;
    for (int k = i; k < j; k++) {
        int cost = MCM(i, k, arr) 
                 + MCM(k + 1, j, arr) 
                 + arr[i - 1] * arr[k] * arr[j];

        mini = min(mini, cost);
    }

    return mini;
}

Memoized->

    int MCM(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
    if (i == j) return 0;

    if (dp[i][j] != -1) return dp[i][j]; 

    int mini = INT_MAX;
    for (int k = i; k < j; k++) {
        int cost = MCM(i, k, arr, dp)
                 + MCM(k + 1, j, arr, dp)
                 + arr[i - 1] * arr[k] * arr[j];

        mini = min(mini, cost);
    }

    return dp[i][j] = mini; 
}

Tabulation->

    int matrixMultiplication(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n - 1];
}



