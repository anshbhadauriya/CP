#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    
    while(t--){
    	int n;
    	cin>>n;
    	
    	vector<int>nums(n);
    	for(int i=0;i<n;i++){
    		cin>>nums[i];
		}
		
		if(nums.size()==2){
			cout<<"YES"<<endl;
			continue;
		}
		unordered_map<int,int>mp;
		for(auto x:nums){
			mp[x]++;
		}
		if(mp.size()>2){
			cout<<"NO"<<endl;
			continue;
		}
		if(mp.size()==1){
			cout<<"YES"<<endl;
			continue;
		}
		vector<int>res;
		for(auto x:mp){
			res.push_back(x.second);
		}
		if(abs(res[0]-res[1])<=1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		
	 
	}



    return 0;
}