class Solution {
public:

/*

agr 0 hai too cost 0 score 0
agr 1 hai too cost 1 and score 1
agr 2 hai too cost 1 and score 2

track cost

*/

int n,m;

int solve(int i,int j,int cost,vector<vector<int>>&grid,int &k,vector<vector<vector<int>>>&dp){

    int temp_cost=0;

    if(grid[i][j]==0){

         temp_cost=0;
     }
     else{ 
        temp_cost=1;
     }

     cost+=temp_cost;

    if(cost>k) return -1;


    if(i==n-1 and j==m-1){

        return grid[i][j];
        
    }

    if(dp[i][j][cost]!=-2) return dp[i][j][cost];

    

     int right=-1,down=-1;
     


     
    //right
    if(j+1<m){
        int temp=solve(i,j+1,cost,grid,k,dp);  
        if(temp!=-1){    //pehle value pta kro ki invalid path hai ya nhi..agr invalid hai so dont add
            right=grid[i][j]+temp;
        }
    }

    //down
    if(i+1<n){
        int temp=solve(i+1,j,cost,grid,k,dp);
        if(temp!=-1){
            down=grid[i][j]+temp;
        }
    }


     return dp[i][j][cost]=max(right,down);

}
    int maxPathScore(vector<vector<int>>& grid, int k) {

        n=grid.size(),m=grid[0].size();

        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m,vector<int>(k+1,-2)));

        return solve(0,0,0,grid,k,dp);
    }
};
