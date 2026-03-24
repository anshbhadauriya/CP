class Solution {
public:
int target;
vector<vector<int>>result;

void dfs(int node,vector<int>&visited,vector<vector<int>>&graph,vector<int>&curr){
    if(node==target){

        result.push_back(curr);
        return;
    }
    visited[node]=1;

    for(auto x:graph[node]){
        if(!visited[x]){
            curr.push_back(x);
            dfs(x,visited,graph,curr);
            curr.pop_back();
        }
    }

    visited[node]=0;

}

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        
         target=graph.size()-1;

         int n=graph.size();

         vector<int>visited(n,0);
         vector<int>curr;
         curr.push_back(0);

        
            
                
                dfs(0,visited,graph,curr);
            
         

         return result;
        

        
    }
};
