class Solution {
public:
    int uniquePaths(int m, int n) {

        /*
Recursion              -> TC: O(2^(m+n))   SC: O(m+n)

Memoization (Top-Down) -> TC: O(m*n)       SC: O(m*n) + O(m+n)

Tabulation (Bottom-Up) -> TC: O(m*n)       SC: O(m*n)

Space Optimized DP     -> TC: O(m*n)       SC: O(n)
*/

        vector<vector<int>>dp(m,vector<int>(n,0));

        dp[m-1][n-1]=1;

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 and j==n-1) continue;

                int right=0,down=0;

                if(j+1<n) right=dp[i][j+1];

                if(i+1<m) down=dp[i+1][j];

                dp[i][j]=right+down;
            }
        }

        return dp[0][0];


        
        
    }
};
