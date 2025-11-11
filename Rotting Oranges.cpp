class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
            q.push({{i,j},0});
            }
            }
        }
        int maximum=0;

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            q.pop();

            maximum=max(maximum,time);

            if(row+1<n and grid[row+1][col]==1){
                grid[row+1][col]=2;
                q.push({{row+1,col},time+1});
            }
            if(row-1>=0 and grid[row-1][col]==1){
                grid[row-1][col]=2;
                q.push({{row-1,col},time+1});
            }
            if(col+1<m and grid[row][col+1]==1){
                grid[row][col+1]=2;
                q.push({{row,col+1},time+1});
            }
            if(col-1>=0 and grid[row][col-1]==1){
                grid[row][col-1]=2;
                q.push({{row,col-1},time+1});
            }



        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return maximum;

    }
};
