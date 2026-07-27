/*
last cell tk jana hai
we can go in all 4 directions thats why dp wont work here (koi rec call grid ke andr hi ghumti reh jaegi)

up down left right

lets try normal dijkstras

dist[i][j] will tell ki iss point pr aane ki minimum cost kitni hogi

to calculate dist[i][j] hme pure path ka max absolute diff pta hona chaiye

so har dist[i][j] = max( maximum abs diff till now , curr abs diff)
*/
#define INF 1e9
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n=heights.size(),m=heights[0].size();

        vector<vector<int>>dist(n,vector<int>(m,INF));

        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        
        pq.push({0,{0,0}});  //dist,{i,j}

        dist[0][0]=0;

        while(!pq.empty()){

            auto it=pq.top(); pq.pop();

            int row=it.second.first;
            int col=it.second.second;
            int curr_dist=it.first;

            /* 
            -1  0  0  1
            0   1  -1  0
             */

             static const int r[4]={-1,0,0,1};
             static const int c[4]={0,1,-1,0};

             for(int i=0;i<4;i++){
                int new_r=row+r[i];
                int new_c=col+c[i];

             

    if(new_r>=0 and new_r<n and new_c>=0 and new_c<m ){
                       int edge = abs(heights[row][col] - heights[new_r][new_c]);
                int newEffort = max(curr_dist, edge);

                if(newEffort<dist[new_r][new_c]){

                    dist[new_r][new_c]=newEffort;

                    pq.push({dist[new_r][new_c],{new_r,new_c}});

                }
                }
                
             }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dist[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        // cout<<n<<" "<<m<<endl;

        return dist[n-1][m-1];




        
    }
};

/*
TC-> O(E log V) -> O(m*n log m*n)
SC-> O(m*n)
*/
