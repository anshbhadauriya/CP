class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();

       
        vector<bool>visited(n,false);

       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; 

        

        pq.push({0,0});
       
        int total_cost=0;

        while(!pq.empty()){

            int cost=pq.top().first;
            int idx=pq.top().second;
            pq.pop();
           
            if(visited[idx]){
            continue;
            }
           
            visited[idx]=true;
            total_cost+=cost;
            

            for(int j=0;j<n;j++){

                if(!visited[j]){
                    int x1=points[idx][0];
                    int y1=points[idx][1];
                    int x2=points[j][0];
                    int y2=points[j][1];
                    int distance=abs(x1-x2)+abs(y1-y2);

                    pq.push({distance,j});
                }

            }




        }

        return total_cost;



    }
};