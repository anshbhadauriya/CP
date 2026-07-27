/*
1 to n nodes

w-> time it takes for a signal to travel from source to target

node k se signal bhejege and we have to tell min time ki sare node tk pohoch jae

so normal bfs can also work

bfs worked! now we can use dijkstra
*/
#define INF 1e9
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>>adj(n+1);

        

        for(auto x:times){
            int u=x[0],v=x[1],w=x[2];

            adj[u].push_back({v,w});
        }

        vector<int>dist(n+1,INF);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
         // dist , ele 


        pq.push({0,k});

        dist[k]=0;

        while(!pq.empty()){

            auto it=pq.top(); pq.pop();
            int curr=it.second;
            int time=it.first;

            if(time>dist[curr]) continue;


            for(auto x:adj[curr]){
                
                int neighbor=x.first;
                int edge=x.second;

                if(time+edge<dist[neighbor]){
                    dist[neighbor]=time+edge;
                    pq.push({time+edge,neighbor});
                }
            }
        }

        int ans=INT_MIN;

        for(int i=1;i<dist.size();i++){

            if(dist[i]==INF) return -1;

            ans=max(ans,dist[i]);
        }

        return ans;
        
    }
};
/*
TC-> O(E log V)
SC-> O(V+E)
*/
