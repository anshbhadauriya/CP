class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        queue<pair<int, pair<int, int>>> q;

        if(grid[0][0]!=0 || grid[grid.size()-1][grid.size()-1]!=0) {
            return -1;
        }
        q.push({1,{0,0}});
        while(!q.empty()) {
            int distance =q.front().first;
            int row =q.front().second.first;
            int column =q.front().second.second;
            q.pop();
            if(row==grid.size()-1 and column==grid[0].size()-1) {
                return distance;
            }

            if(row-1>=0 && grid[row-1][column]==0 &&
                !visited[row-1][column]) {
                q.push({distance+1,{row-1,column}});
                visited[row-1][column]=1;
            }

            if(row+1<grid.size() && grid[row+1][column]==0 &&
                !visited[row+1][column]) {
                q.push({distance+1,{row+1,column}});
                visited[row+1][column]=1;
            }

            if(column-1>=0 && grid[row][column-1]==0 &&
                !visited[row][column-1]){
                q.push({distance+1, {row,column-1}});
                visited[row][column - 1] = 1;
            }

            if(column + 1 < grid[0].size() && grid[row][column + 1] == 0 &&
                !visited[row][column + 1]) {
                q.push({distance + 1, {row, column + 1}});
                visited[row][column + 1] = 1;
            }

            if(row - 1 >= 0 && column - 1 >= 0 &&
                grid[row - 1][column - 1] == 0 &&
                !visited[row - 1][column - 1]) {
                q.push({distance + 1, {row - 1, column - 1}});
                visited[row - 1][column - 1] = 1;
            }

            if(row - 1 >= 0 && column + 1 < grid[0].size() &&
                grid[row - 1][column + 1] == 0 &&
                !visited[row - 1][column + 1]) {
                q.push({distance + 1, {row - 1, column + 1}});
                visited[row - 1][column + 1] = 1;
            }

            if(row + 1 < grid.size() && column - 1 >= 0 &&
                grid[row + 1][column - 1] == 0 &&
                !visited[row + 1][column - 1]) {
                q.push({distance + 1, {row + 1, column - 1}});
                visited[row + 1][column - 1] = 1;
            }

            if(row + 1 < grid.size() && column + 1 < grid[0].size() &&
                grid[row + 1][column + 1] == 0 &&
                !visited[row + 1][column + 1]) {
                q.push({distance + 1, {row + 1, column + 1}});
                visited[row + 1][column + 1] = 1;
            }
        }
        return -1;
    }
};
