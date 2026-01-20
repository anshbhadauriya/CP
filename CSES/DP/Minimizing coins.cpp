#include <bits/stdc++.h>
using namespace std;


int solve(vector<int>&money,int target,int i,vector<vector<int>>&dp){
	if(i==money.size()){
		return 1e9;
	}
	if(target==0){
		return 0;
	}
	if(dp[i][target]!=-1){
		return dp[i][target];
	}
	if(money[i]<=target){
		int take=1+solve(money,target-money[i],i,dp);
		int skip=solve(money,target,i+1,dp);
		return dp[i][target]=min(take,skip);
	}
	else{
		return dp[i][target]=solve(money,target,i+1,dp);
	}
	
}

int main(){
	int n;
	cin>>n;
	int target;
	cin>>target;
	vector<int>money(n);
	vector<vector<int>>dp(n,vector<int>(target+1,-1));
	for(int i=0;i<n;i++){
		cin>>money[i];
	}
	int ans= solve(money,target,0,dp);
	 if(ans >= 1e9){
	  cout << -1 << endl; 
}
    else{
	 cout << ans << endl;  
}

}