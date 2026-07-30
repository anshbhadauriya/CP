class Solution {
  public:
  
  void dfs(int curr,vector<vector<int>>&reverseAdjGraph,vector<bool>&visited){
      
      visited[curr]=true;
      
      for(auto x:reverseAdjGraph[curr]){
          
          if(!visited[x]){
              dfs(x,reverseAdjGraph,visited);
          }
      }
  }
  
  void topoSort(int curr,vector<bool>&visited,stack<int>&st,vector<vector<int>>&adj){
      
      visited[curr]=true;
      
      for(auto x:adj[curr]){
          
          if(!visited[x]){
              
              topoSort(x,visited,st,adj);
          }
      }
      
      st.push(curr);
  }
    int kosaraju(int V, vector<vector<int>> &edges) {

        //make adj list
        
        vector<vector<int>>adj(V);
        
        for(auto x:edges){
            int u=x[0],v=x[1];
            
            adj[u].push_back(v);
        }
        
        //step 1-> now Toposort
        
        stack<int>st;
        
        vector<bool>visited(V,false);
        
       
        
        for(int i=0;i<V;i++){
            
        if(!visited[i]){
    
        topoSort(i,visited,st,adj);
        
        }
        }
        
        //step 2-> make a reverse graph
        
        vector<vector<int>>reverseAdjGraph(V);
        
        for(int u=0;u<V;u++){
            
            for(auto v:adj[u]){
                reverseAdjGraph[v].push_back(u);
            }
        }
        
        
        //step 3-> abh dfs kro based on stack order
        
        //visited dobara use hoga too make it fresh
        
        for(int i=0;i<V;i++) visited[i]=false;
        
        int SCC=0;  //strongly connected components
        
        while(!st.empty()){
            
            int curr=st.top();
            st.pop();
            
            if(!visited[curr]){
                SCC++;
                dfs(curr,reverseAdjGraph,visited);
            }
        }
        
        
        return SCC;
        
    }
};

/*
Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/
