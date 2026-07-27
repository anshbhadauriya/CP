/*
cheapest cost from src to dst with at most k stops
stops mtlb nodes in bwtween source to destination
Dijkstra's algorithm will not work here kyuki isme har state ke lie number of stops bhi dekhne pdege but uk in dijkstra we save min dist to reach a noed but not how many stops taken to reach that node...try to dry run sum test cases you will be able to understand that why Dijkstra fails here

suppose agr kahi destination pr jan hai and if we use Dijkstra so it will choose min path 
so min path ke chakkr me it will not care about stops so Dijkstra always chases min path 
and distance vector me uss cell tak pohochne ka min cost fill krdega without caring about ki yha tk aane me kitne stops lage but actual me stops do matter 

so better is to use bfs here but plain bfs will give tle

we can use level order traversal just like we use in trees
level 1 src
level 1 will hold ki src se ham kon kon se node tk ja skte
level 2 

so aisse krke ham max level k+1 tk ja skte aur iss level pr agr destination mile too uska uska min cost nikal lo agr iss level pr destination nhi milta too so need to go further 

this shi wasted my 2hrs
*/
#define INF 1e9
#define ll long long
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        //first make adj list

        vector<vector<pair<int,int>>>adj(n);

        for(auto x:flights){
            int u=x[0],v=x[1],weight=x[2];

            adj[u].push_back({v,weight});
        }


        

        queue<pair<int,int>>q; //node ,dist

        

        q.push({src,0});

        int level=0,minimum=INT_MAX;
/*
0 ----100----> 1
 \----200----> 1
 \----300----> 1
 here 0 to 100 to 1 is always better so why to explore 0 to 200 to 1 and 0 to 300 to 1
to prevent exploring the same node multiple times we have to use distance vector which will store distance till now..
*/
       vector<int>distance(n,INF);

       distance[src]=0;

        while(!q.empty() and level<=k){

            int size=q.size();

            for(int i=0;i<size;i++){
            int curr=q.front().first;
            int dist=q.front().second;
            q.pop();
            

            for(auto x:adj[curr]){

                int neighbor=x.first;
                int edge=x.second;

                if(edge+dist<distance[neighbor]){
                    distance[neighbor]=dist+edge;
                q.push({neighbor,dist+edge});

                }
                
            }

           

            }
             level++;

            
        }

        return (distance[dst]==INF)?-1:distance[dst];



        
    }
};
/*
TC-> O((V+E)*k) bcs k times
SC-> O(V+E)
*/
