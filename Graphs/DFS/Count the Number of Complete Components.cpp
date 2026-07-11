/*
so basically

n vertices 0 to n-1 

edges (undirected)

return krna hai number of connected components

connected components-> graph ki kisi bhi node se kisi aur node tk pohoch skte ho agr then it is called as connected
                       components

complete connected components-> sare nodes sare nodes se connected hone chaiye that means there should be a direct
path bw all nodes

so we can say har node ki indegree n-1 honi chaiye

*/
class Solution {
public:

int dfs(int curr,vector<vector<int>>&adj,vector<int>&visited,int &n,int &count,int &degree){

    visited[curr]=1;

    count++;

    degree+=adj[curr].size(); 

    for(auto x:adj[curr]){
        if(!visited[x]){
            dfs(x,adj,visited,n,count,degree);
        }
    }

    return count;
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>>adj(n);
        // vector<int>indegree(n,0);
        for(auto x:edges){
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
     
        }

        //abh hme indegree or adj matrix mil gya



        //abh pta kro kis node ke subgraph me kitne nodes hai

        //agr koi connected component hoga jisme k nodes hogi too if it has k(k-1)/2 edges then it is called as complete

        vector<int>visited(n,0);

        int ans=0;

        for(int i=0;i<n;i++){
            if(!visited[i]){
            int count=0;
            int degree=0;
            int total_nodes=dfs(i,adj,visited,n,count,degree);

            cout<<degree<<endl;

            int total_edges=degree/2;  //kyuki graph undirected hai and each node is counted as twice

            if(total_nodes*(total_nodes-1)/2==total_edges) ans++;

            }
        }

        return ans;




        
    }
};
