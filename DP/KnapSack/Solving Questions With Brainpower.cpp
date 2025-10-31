class Solution {
public:
    long long solve(vector<vector<int>>&questions,int idx,vector<long long>& dp) {
        if (idx >=questions.size()){
            return 0;
        }
        if (dp[idx]!=-1) {
            return dp[idx];
        }

        return dp[idx] = max(
            (long long)questions[idx][0] + solve(questions, idx + questions[idx][1] + 1, dp),
            solve(questions, idx + 1, dp)
        );
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return solve(questions, 0, dp);
    }
};
