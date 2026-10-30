/*
so pehle too hame maximum path pr dhyan dena hai
fir atmost k consecutives pr
so can we try all paths? 
raste me k consecutive cross hojae too break
use dijkstra
doneeee!
*/
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        if(n==1) return 0;

        vector<vector<pair<int,int>>>adj(n);
         vector<vector<int>>dist(n,vector<int>(k+1,1e9));  //dist ko 2d rkha bcs different consecutive counts represents different states

        for(auto x:edges){
            int u=x[0],v=x[1],w=x[2];
            adj[u].push_back({v,w});
        }

        priority_queue<pair<pair<int,int>,pair<char,int>>,vector<pair<pair<int,int>,pair<char,int>>>,greater<pair<pair<int,int>,pair<char,int>>>>pq;

        int src=0;

        dist[src][1]=0;

        pq.push({{0,src},{labels[src],1}});  //{cost,node} {curr_label,consecutives}

        while(!pq.empty()){

            auto it=pq.top(); pq.pop();

            int curr_cost=it.first.first;
            int curr_node=it.first.second;
            char curr_label=it.second.first;
            int consecutive=it.second.second;


            if(curr_cost>dist[curr_node][consecutive]) continue;

            for(auto x:adj[curr_node]){

                int adj_node=x.first;
                int adj_weight=x.second;

                int next=(curr_label==labels[adj_node])?consecutive+1:1;
                if(next > k) continue;

            if(curr_cost+adj_weight<dist[adj_node][next]){

                 dist[adj_node][next]=curr_cost+adj_weight;                

                pq.push({{dist[adj_node][next],adj_node},{labels[adj_node],next}});
            }
            }

        }

        int ans=*min_element(dist[n-1].begin(),dist[n-1].end());


        return ans==1e9?-1:ans;



    }
};
