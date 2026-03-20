#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    int n;
    cin>>n;
    vector<pair<int,int>>nums;
    
    for(int i=0;i<n;i++){
    	
    	int u; cin>>u;
    	int v; cin>>v;
    	
    	nums.push_back({u,1});
    	nums.push_back({v,-1});
	}
	
	sort(nums.begin(),nums.end());
	
	int count=0,maximum=1;
	
	for(int i=0;i<nums.size();i++){
		count+=nums[i].second;
		if(count>maximum) maximum=count;
	}
	
	cout<<maximum;
	
	
    
    

    return 0;
}