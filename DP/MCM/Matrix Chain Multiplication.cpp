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


    

