#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countsubset(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1]) {
                    dp[i][j] = dp[i][j] + dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][target];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum + target) % 2 != 0 || sum < abs(target))
            return 0;

        int ans = (target + sum) / 2;
        return countsubset(nums, ans);
    }
};

int main() {
    Solution obj;
    int n, target;

    vector<int> nums;
    
    for (int i = 1; i <=6; i++) {
        nums.push_back(i);
    }

    cin >> target;

    int result = obj.findTargetSumWays(nums, target);
    cout << result << endl;

    return 0;
}
