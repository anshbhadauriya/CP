DP+DFS 

class Solution {
public:

 int dfs(int row, int col, vector<vector<int>>& matrix,vector<vector<int>>&dp){
        if(dp[row][col]!=-1) return dp[row][col];
        int n = matrix.size();
        int m = matrix[0].size();
      
        int ans=1;

        if(row+1<n && matrix[row + 1][col]>matrix[row][col]) {
            ans=max(ans,1+dfs(row+1,col,matrix,dp));
        }

        if(row-1>=0 && matrix[row - 1][col]>matrix[row][col]) {
          ans=max(ans,1+dfs(row-1,col,matrix,dp));
        }

        
        if(col+1<m && matrix[row][col + 1]>matrix[row][col]) {
            ans=max(ans,1+dfs(row,col+1,matrix,dp));
        }

        if(col-1>=0 && matrix[row][col-1]>matrix[row][col]) {
            ans=max(ans,1+dfs(row,col-1,matrix,dp));
        }

        return dp[row][col]=ans;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int maximum=1;
        vector<vector<int>>dp(n,vector<int>(m,-1));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maximum=max(maximum,dfs(i,j,matrix,dp));
            }
        }
        return maximum;
    }
};
