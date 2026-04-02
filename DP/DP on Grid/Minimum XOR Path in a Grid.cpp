class Solution {
public:
    int n,m;
    

    int solve(int i,int j,int xorr,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        if(i==n-1 and j==m-1){
            return xorr^grid[i][j];
        }
        if(dp[i][j][xorr]!=-1) return dp[i][j][xorr];

        int down=INT_MAX,right=INT_MAX;

        if(i+1<n){
            down=solve(i+1,j,xorr^grid[i][j],grid,dp);
        }
        if(j+1<m){
            right=solve(i,j+1,xorr^grid[i][j],grid,dp);
        }

        return dp[i][j][xorr]=min(down,right);

        
        
    }
    
    int minCost(vector<vector<int>>& grid) {

        n=grid.size(),m=grid[0].size();
vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(1024,-1)));
        return solve(0,0,0,grid,dp);
        
    }
};
