class Solution {
public:

void dfs(vector<vector<int>>& rooms,vector<int>&visited,int x){

    visited[x]=1;


    for(auto node :rooms[x]){
        if(!visited[node]){        //simple dfs
        dfs(rooms,visited,node);
        }
    }




}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>visited(n,0);

        



        int x=0;
         dfs(rooms,visited,x);
        

        for(int i=0;i<visited.size();i++){
            if(visited[i]==0){
                return false;     //if there is any unvisited room return false
            }
        }
        return true;
    }
};
