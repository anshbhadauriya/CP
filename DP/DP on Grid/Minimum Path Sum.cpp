class Solution {
public:
int n,m;
int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
    if(i==n-1 and j==m-1) return grid[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int down=INT_MAX,right=INT_MAX;
    if(i+1<n){
        down=solve(i+1,j,grid,dp);
    }
    if(j+1<m){
        right=solve(i,j+1,grid,dp);
    }

    return dp[i][j]=grid[i][j]+min(down,right);
}
    int minPathSum(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
         vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,grid,dp);
    }
};