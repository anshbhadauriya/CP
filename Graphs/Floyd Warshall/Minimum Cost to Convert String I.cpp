class Solution {
public:
const int INF=1e8;  

void floydwarshall(vector<vector<long long>>&dist,vector<char>& original,vector<char>& changed,vector<int>& cost){

    for(int i=0;i<original.size();i++){
        int s=original[i]-'a';     
        int t=changed[i]-'a';
        dist[s][t]=min(dist[s][t], 1LL*cost[i]);   //given cost ko pehle daal do
    }

    for(int k=0;k<26;k++){   //via this node
        for(int i=0;i<26;i++){  //starting node
            for(int j=0;j<26;j++){  //destination node
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }       
    }

}
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>dist(26,vector<long long>(26,INF));

        floydwarshall(dist,original,changed,cost);


        long long count=0;
        for(int i=0;i<source.size();i++){
            if(source[i]==target[i]){   //pehle se hi same ho too skip
                continue;
            }

            if(dist[source[i]-'a'][target[i]-'a']==1e8){
                return -1;  //impossible kyuki kabhi reach nhi hoga
            }

            count+=dist[source[i]-'a'][target[i]-'a'];
        }

        return count;
    }
};