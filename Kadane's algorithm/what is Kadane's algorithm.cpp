	#include <bits/stdc++.h>
	using namespace std;

	int solve(vector<int>&coins,int target,int i,vector<vector<int>>&dp){
		
		if(i==coins.size()){
			if (target == 0) return 1;
			return 0;
		}
		if(dp[i][target]!=-1){
			return dp[i][target];
		}
		int take = 0;
     	if(coins[i] <= target){
       take = solve(coins, target - coins[i], i, dp); 
		}

     int skip = solve(coins, target, i + 1, dp); 
      return dp[i][target] = take + skip;

	}

	int main(){
		int n,target;
		cin>>n;
		cin>>target;
		vector<int>coins(n);
		vector<vector<int>>dp(n,vector<int>(target+1,-1));
		int count=0;
		for(int i=0;i<n;i++){
			cin>>coins[i];
		}
	int ans=solve(coins,target,0,dp);
		cout<<ans;
		
	}