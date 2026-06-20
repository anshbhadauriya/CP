Q1->
  class Solution {
public:
    vector<string> createGrid(int m, int n) {

        string temp(n,'#');

        vector<string>grid;

        string temp1(n,'.');
        grid.push_back(temp1);

        for(int i=0;i<m-1;i++){
            grid.push_back(temp);
        }

        for(auto &x:grid){
            x[x.size()-1]='.';
        }

        return grid;
        
        
    }
};

Q2->
  class Solution {
public:
    int minLights(vector<int>& lights) {

        int n=lights.size();

        int glow=0;

        vector<int>temp(n,0);

        for(int i=0;i<n;i++){
            if(lights[i]>0){
                if(lights[i]<glow){
                glow--;
                    temp[i]++;
                    continue;
                }
                temp[i]++;
                glow=max(glow,lights[i]);
            }
            else{
                if(glow){
                    temp[i]++;
                    glow--;
                }
            }
        }

        int glow2=0;

        for(int i=n-1;i>=0;i--){

            if(lights[i]>0){
                if(lights[i]<glow2){
                glow2--;
                    temp[i]++;
                    continue;
                }
                temp[i]++;
                glow2=max(glow2,lights[i]);
                
            }
            else{

                if(glow2){
                    temp[i]++;
                    glow2--;
                }
            }
        }

        // for(auto x:temp) cout<<x<<" ";
        // cout<<endl;

        //abh bss consecutive nikalo

        int ans = 0, zeros=0;

for(int i=0;i<n;i++){

    if(temp[i]==0){
        zeros++;
    }
    else{
        ans+=(zeros+2)/3; // ceil(zeros/3)
        zeros = 0;
    }
}

ans+=(zeros+2)/3;

return ans;
        
    }
};

Q3->

  class Solution {
public:
long long dfs(int node,vector<vector<int>>&adj,vector<int>&baseTime){

    if(adj[node].empty()) return baseTime[node];

    long long earliest=LLONG_MAX,latest=LLONG_MIN;

    for(auto x:adj[node]){

        long long child=dfs(x,adj,baseTime);

        earliest=min(earliest,child);

        latest=max(latest,child);
    }

    long long ownDuration=(latest-earliest)+baseTime[node];

    return latest+ownDuration;
}
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        
        vector<vector<int>>adj(n);

        for(auto x:edges){
            int u=x[0],v=x[1];
            adj[u].push_back(v);
        }

        return dfs(0,adj,baseTime);
    }
};
