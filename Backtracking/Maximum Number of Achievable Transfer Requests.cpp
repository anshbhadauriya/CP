//make recursion tree and this will become like subsets problem (take or skip)
https://www.youtube.com/watch?v=eY4PHr1DPp0&list=PLpIkg8OmuX-KJPC18SGiRUzJQAYo839ox&index=6


class Solution {
public:
int maximum=-1;
void solve(int idx,vector<vector<int>>& requests,vector<int>&temp,int &take){

    if(idx==requests.size()){
        for(int i=0;i<temp.size();i++){
            if(temp[i]!=0) return;
        }

        maximum=max(maximum,take);
        return;

    }
    int u=requests[idx][0],v=requests[idx][1];

    temp[u]-=1;
    temp[v]+=1;

    take+=1;

    solve(idx+1,requests,temp,take);
    temp[u]+=1;
    temp[v]-=1;
    take-=1;

    solve(idx+1,requests,temp,take);


}
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>temp(n,0);
        int take=0;

        solve(0,requests,temp,take);
        return maximum;
        
    }
};
