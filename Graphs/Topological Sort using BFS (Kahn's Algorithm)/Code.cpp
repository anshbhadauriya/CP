class Solution {
  public:
   /*
  abh ham log topological sort bfs se krege (Kahn's algo)
  
  check kro vertex ki indegree 0 hai, jiski bhi 0 hai usse queue me dalo
  
  fir usse ans me dalo aur remove kro graph se so when u remove it from graph so others
  indegree (jisse removed wala connected tha) will get reduced so jis ki bhi indegree 0 hojae 
  usse remove kro aur queue me dalo 
  
  keep repeating until sabki indegree 0 na hojae
 
  */
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(V);
        
        vector<int>indegree(V,0);
        
        for(auto x:edges){
            int u=x[0],v=x[1];
            
            adj[u].push_back(v);
            
            indegree[v]++;
        }
        
        queue<int>q;
        
        for(int i=0;i<V;i++){
            
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int>ans;
        
        while(!q.empty()){
            
            int node=q.front();
            
            q.pop();
            
            ans.push_back(node);
            
            for(auto x:adj[node]){
                indegree[x]--;
                if(indegree[x]==0) q.push(x);
            }
        }
        
        return ans;
        
        
        
    }
};