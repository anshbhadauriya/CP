class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        
        vector<vector<pair<int,int>>>adj(V);
        
        for(auto x:edges){
            int u=x[0],v=x[1],w=x[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int>distance(V,1e9);
        
        distance[src]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,src});
        
        
        while(!pq.empty()){
            
            int curr_distance=pq.top().first;
            int curr_node=pq.top().second;
            pq.pop();
            
            for(auto x:adj[curr_node]){
                int next_node=x.first;
                int weight=x.second;
                
                if(distance[next_node]>weight+curr_distance){
                    distance[next_node]=weight+curr_distance;
                    pq.push({distance[next_node],next_node});
                }
            }
        }
        
        return distance;
        
        
        
    }
};