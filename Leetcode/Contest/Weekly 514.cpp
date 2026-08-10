Q1->
  class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {

        double MOD=1e5;
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());

        double ans=0;
        int i=0;
        for(i=0;i<min(prices.size(),discounts.size());i++){

            double curr=(1.00*prices[i]*(100.00-(1.00*discounts[i])))/100.00;

            ans=(ans+curr);
        }

        while(i<prices.size()){
            ans+=prices[i];
            i++;
        }


        return ans;

        
        
    }
};
Q2->
  class Solution {
public:
    long long height=-1e9;

    void findHeight(int i,int curr_height,vector<vector<int>>&adj){

        if(curr_height>height) height=curr_height;
        
        for(auto x:adj[i]){
            findHeight(x,curr_height+1,adj);
        }

        return;
    }

    
    void dfs(int i,int depth,long long &sum,vector<vector<int>>&adj,vector<int>&parent,vector<int>&nums){

        sum+=nums[i]*(height-depth+1);

        for(auto x:adj[i]){
            dfs(x,depth+1,sum,adj,parent,nums);
        }

        return;
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {

        //pehle adj list bana lo

        int n=nums.size();
        
        vector<vector<int>>adj(n);

        for(int i=1;i<n;i++){

            adj[parent[i]].push_back(i);
        }

        //find height

        findHeight(0,1,adj);
        

        

        //now just do dfs ?

        long long sum=0;

        dfs(0,1,sum,adj,parent,nums);

        return sum;
    }
};
