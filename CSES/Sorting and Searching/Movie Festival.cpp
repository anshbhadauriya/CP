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
    	int  v; cin>>v;
    	nums.push_back({v,u});
	}
	
	sort(nums.begin(),nums.end());
	int prev_time=-1,count=0;
	for(int i=0;i<n;i++){
		
		int start=nums[i].second;
		int end=nums[i].first;
		
		if(start>=prev_time){
			count++;
			prev_time=end;
		}
		
		
	}
	
	cout<<count;
	
	
    
    

    return 0;
}