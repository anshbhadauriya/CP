class Solution {
public:
void bfs(int sr,int sc,int color,vector<vector<int>>&visited,vector<vector<int>>&image){
    int n=image.size();
    int m=image[0].size();
    int prev=image[sr][sc];
        if(prev==color){
            return ;
        }
    visited[sr][sc]=1;
    image[sr][sc]=color;
    queue<pair<int,int>>q;
    q.push({sr,sc});
    int arr1[4]={-1,1,0,0};
    int arr2[4]={0,0,-1,1};
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nrow=row+arr1[i];
            int ncol=col+arr2[i];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !visited[nrow][ncol] and image[nrow][ncol]==prev){
                image[nrow][ncol]=color;
                visited[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }
        

    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        bfs(sr,sc,color,visited,image);
        return image;
    }
};
