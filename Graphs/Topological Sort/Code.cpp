class Solution {
  public:
  
  /*
  Intution is ki agr kisi node par nhi jaa pa rhe too usse upr rkho stack me 
  aur kisi node jaa pa rhe too usse depth  me rkho stack ke
  
  so when you pop out stack so jis ele me nhi ja pa rhe will come at front and 
  jidr easily ja pa rhe vo last me

A node should appear only after all of its outgoing neighbours
have been processed.

So during DFS, first visit all neighbours recursively.
When we return back (i.e., the node is fully processed),
push it into the stack.

Nodes finish in reverse topological order.
Hence popping the stack gives the correct topological ordering.
*/
  
  stack<int>st;
  
  void dfs(int i,vector<vector<int>>&adj,vector<bool>&visited){
      
      visited[i]=true;
      
      for(auto x:adj[i]){
          if(!visited[x]){
              dfs(x,adj,visited);
          }
      }
      
      st.push(i);
  }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        
        vector<bool>visited(V,false);
        
        vector<vector<int>>adj(V);
        
        for(auto x:edges){
            
            int u=x[0],v=x[1];
            
            adj[u].push_back(v);
        }
        
        for(int i=0;i<V;i++){
            if(!visited[i]) 
             dfs(i,adj,visited);
        }
        
        vector<int>ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;

        
    }
};
