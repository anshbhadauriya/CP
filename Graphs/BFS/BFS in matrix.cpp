class Solution {
public:
void bfs(int ro,int co,vector<vector<int>>&visited,vector<vector<char>>& grid){
    visited[ro][co]=1;
    queue<pair<int,int>>q;
    q.push({ro,co});
    int n=grid.size();
    int m=grid[0].size();

    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();

        if(row+1<n and grid[row+1][col]=='1' and !visited[row+1][col]){
            visited[row+1][col]=1;
            q.push({row+1,col}); 
        }

        if(row-1>=0 and grid[row-1][col]=='1' and !visited[row-1][col]){
            visited[row-1][col]=1;
            q.push({row-1,col}); 
        }

        if(col+1<m and grid[row][col+1]=='1' and !visited[row][col+1]){
            visited[row][col+1]=1;
            q.push({row,col+1}); 
        }
        if(col-1>=0 and grid[row][col-1]=='1' and !visited[row][col-1]){
            visited[row][col-1]=1;
            q.push({row,col-1}); 
        }

    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' and !visited[i][j]){
                    count++;
                    bfs(i,j,visited,grid);
                }
            }
        }
        return count;
    }
};