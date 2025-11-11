class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;

        
        if (row + 1 < n && grid[row + 1][col] == '1' && !visited[row + 1][col]) {
            dfs(row + 1, col, visited, grid);
        }

     
        if (row - 1 >= 0 && grid[row - 1][col] == '1' && !visited[row - 1][col]) {
            dfs(row - 1, col, visited, grid);
        }

        
        if (col + 1 < m && grid[row][col + 1] == '1' && !visited[row][col + 1]) {
            dfs(row, col + 1, visited, grid);
        }

        if (col - 1 >= 0 && grid[row][col - 1] == '1' && !visited[row][col - 1]) {
            dfs(row, col - 1, visited, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    dfs(i, j, visited, grid);
                }
            }
        }
        return count;
    }
};
