class Solution {
  public:
  
  bool detect(int src,vector<vector<int>>&adj,vector<int>&visited){
      
      visited[src]=1;
      
      queue<pair<int,int>>q;
      
      q.push({src,-1});
      
      while(!q.empty()){
          
          int node=q.front().first;
          int parent=q.front().second;
          q.pop();
          
          for(auto adj_node:adj[node]){
              if(!visited[adj_node]){
                  visited[adj_node]=1;
                  q.push({adj_node,node});
              }
              else if(parent!=adj_node){
                  return true;
              }
          }
          
      }
      return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        for(auto x:edges){
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>visited(V,0);
        
        for(int i=0;i<V;i++){
            
            if(!visited[i]){
                if(detect(i,adj,visited)){
                    return true;
                }
            }
        }
        return false;
        
    }
};