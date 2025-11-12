class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>visited(mat.size(),vector<int>(mat[0].size(),0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    visited[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            mat[row][col]=steps;
            if(row-1>=0 and !visited[row-1][col] and mat[row-1][col]==1){
                visited[row-1][col]=1;
                q.push({{row-1,col},steps+1});
            }
            if(row+1<mat.size() and !visited[row+1][col] and mat[row+1][col]==1){
                visited[row+1][col]=1;
                q.push({{row+1,col},steps+1});
            }
            if(col-1>=0 and !visited[row][col-1] and mat[row][col-1]==1){
                visited[row][col-1]=1;
                q.push({{row,col-1},steps+1});
            }
            if(col+1<mat[0].size() and !visited[row][col+1] and mat[row][col+1]==1){
                visited[row][col+1]=1;
                q.push({{row,col+1},steps+1});
            }
        }
        return mat;
    }
};
