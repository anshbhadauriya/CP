class Solution {
public:
int maximum=0;
void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& grid,int &count) {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col]=1;
        count+=grid[row][col];
        maximum=max(maximum,count);

        
        if(row+1<n  && !visited[row+1][col] and grid[row+1][col]!=0) {
            dfs(row + 1, col, visited, grid,count);
        }

     
        if(row-1>=0  && !visited[row-1][col] and grid[row-1][col]!=0) {
            dfs(row - 1, col, visited, grid,count);
        }

        
        if(col+1<m  && !visited[row][col+1] and grid[row][col+1]!=0) {
            dfs(row, col + 1, visited, grid,count);
        }

        if(col-1>=0  && !visited[row][col-1] and grid[row][col-1]!=0) {
            dfs(row,col-1,visited,grid,count);
        }
        count-=grid[row][col];   //backtrack kro
        visited[row][col]=0;
    }


    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0)
                dfs(i,j,visited,grid,count);
            }
        }
        return maximum;
    }
};
