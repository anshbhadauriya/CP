/*
yeh batana hai ki kon se cell se ham pacific aur atlantic ocean ja skte hai
pacific is first row and left side column
atlantic is last row and right side column

lekin ek cell se dusre cell tabhi ja skte jab curr cell >= next cell
bfs dfs both can work
but lets go for bfs bcs its more suitable here

doing bfs from every cell is giving tle at last tc

so now instead of doing bfs from island to oceans

do oceans to island

dono oceans se bfs kro aur dekho kaha kaha tk ja pa rhe
*/
class Solution {
public:

int n,m;

void bfs(vector<pair<int,int>>& sources,vector<vector<bool>>& visited,vector<vector<int>>& heights){

 

    queue<pair<int,int>>q;
    
    for(auto cell:sources) {
            int r=cell.first;
            int c=cell.second;

            if(!visited[r][c]) {
                visited[r][c]=true;
                q.push({r,c});
            }
        }

        static const int dr[4] = {-1, 1, 0, 0};
        static const int dc[4] = {0, 0, -1, 1};

        while(!q.empty()){

            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int k=0;k<4;k++) {

                int nr=r+dr[k];
                int nc=c+dc[k];

                if(nr>=0 and nr <n and nc>=0 and nc<m and !visited[nr][nc] and heights[nr][nc]>=heights[r][c]){

                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        n=heights.size(),m=heights[0].size();

        vector<vector<bool>>pacific(n,vector<bool>(m,false));
        vector<vector<bool>>atlantic(n,vector<bool>(m,false));

        vector<pair<int,int>>pacificSources,atlanticSources;

        //pacific first row and leftside col
        for(int j=0;j<m;j++){
            pacificSources.push_back({0,j});
        }

        for(int i=0;i<n;i++){
            pacificSources.push_back({i,0});
        }

          //atlantic last row and right col
        for(int i=0;i<n;i++){
            atlanticSources.push_back({i,m-1});
        }

        for(int j=0;j<m;j++){
            atlanticSources.push_back({n-1,j});
        }

        bfs(pacificSources,pacific,heights);
        bfs(atlanticSources,atlantic,heights);

        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] and atlantic[i][j]) ans.push_back({i,j});
            }
        }

        return ans;

        
    }
};
/*
Pacific BFS -> O(m × n)
Atlantic BFS -> O(m × n)

so overall O(m x n)

sc is also O(m*n)
*/
