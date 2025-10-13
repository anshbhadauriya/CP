Tabulation->

    Step 1-> pehle Longest Common Subsequence wala code likho
    Step 2-> Backtrack to find the actual subsequence
    string lcs = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs += s1[i - 1];  // include character
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(lcs.begin(), lcs.end()); // reverse to get correct order
    return lcs;
}




Recursive->

    
class Solution {
public:
    string solve(string &text1, string &text2, int i, int j, vector<vector<string>> &dp) {
        if(i==0 || j==0) {
          return ""; 
    }

        if(dp[i][j]!=""){
          return dp[i][j]; 
        }

        if(text1[i-1]==text2[j-1]) {
            dp[i][j]=solve(text1, text2, i-1, j-1, dp)+text1[i-1];
        } else {
            string left = solve(text1, text2, i-1, j,dp);
            string right = solve(text1, text2, i, j-1,dp);
            if(left.size() > right.size()) {
                dp[i][j] = left;
            } else {
                dp[i][j] = right;
            }
        }
        return dp[i][j];
    }

    string longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<string>> dp(n+1, vector<string>(m+1, ""));
        return solve(text1, text2, n, m, dp);
    }
};
