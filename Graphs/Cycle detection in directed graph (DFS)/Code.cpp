/*
if node is already visited on the same path than it is cyclic

mtlb agr kisi path me travel kr rhe ho too uss path ko visted mark krte rho aur suppose koi node hai vo already visited hai aur vo same path me bhi aachuka hai mtlb vo same path me dusri
baar mila mtlb that is cyclic
*/

class Solution {
  public:
  
  bool dfs(int i,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&path){
      
      visited[i]=true;
      path[i]=true;
      
      for(auto x:adj[i]){
          
          if(!visited[x]){
              
              if(dfs(x,adj,visited,path)) return true;
          }
          else if(path[x]) return true;
      }
      
      path[i]=false;
      
      return false;
      
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>>adj(V);
        
        for(auto x:edges){
            int u=x[0],v=x[1];
            
            adj[u].push_back(v);
        }
        
        vector<bool>visited(V,false),path(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,path)) return true;
            }
        }
        
        return false;
        
    }
};
