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
            int drow[4]={-1,1,0,0};
            int dcol[4]={0,0,-1,1};

            for(int i=0;i<4;i++){
                int new_row=row+drow[i];
                int new_col=col+dcol[i];

        if(new_row<n and new_row>=0 and new_col<m and new_col>=0 and grid[new_row][new_col]==1){
                    grid[new_row][new_col]=2;
                    q.push({{new_row,new_col},time+1});
                }
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
