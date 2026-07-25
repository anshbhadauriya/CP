// adj list is given

// temrinal node-> outdegree 0

// safe node-> everypath starting with that node leads to terminal node

// return krna hai array jisme sare safe nodes ho

/* accha agr 0 se shuru krege too cycle form hoskti hai
0 - 1 - 3 - 0

jo bhi node cycle ka part hai usse include nhi krna hai bss

so one way is ki do topo sort from all unvisited node

but how to end topo sort here bcs we are not sure about number of nodes

we can do normal cycle detection using dfs or smthng and return all nodes which
are not cyclic

previously also i have not used topo sort here

so lets do this using dfs first
*/
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited, vector<int>& path, vector<int>& check) {
      visited[node]=1;
      path[node]=1;

      for(auto x:graph[node]){

        if(!visited[x]){

            if(dfs(x,graph,visited,path,check)){
                check[node]=0;//mark as unsafe
                return true;
            }
        }

        else if(visited[x] and path[x]){ //cycle found
            check[node]=0;  //mark as unsafe
            return true;  //parent ko bhi batao ki path me cycle hai
            }

      } 
      check[node]=1;  //reached terminal node so mark it as safe
      path[node]=0;
      return false; 
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visited(n,0),path(n, 0),check(n, 0);
        vector<int>result;

        //check will store ki konsa node safe hai

        for (int i=0;i<n;i++) {
            if (!visited[i]) {
                dfs(i,graph,visited,path,check);
            }
        }

        for(int i=0;i<n;i++) {
            if(check[i]==1) {
                result.push_back(i);
            }
        }

        return result;
    }
};

/*
TC-> O(V+E)
SC-> O(V)
*/
