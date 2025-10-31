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
		unordered_map<int,int>mp;
		vector<int>freq;
		for(auto x:nums){
			mp[x]++;
		}
		for(auto x:mp){
			freq.push_back(x.second);
			
		}
		sort(freq.begin(),freq.end());
		int maximum=0;
		for(int i=0;i<freq.size();i++){
			int count=0;
			for(int j=0;j<freq.size();j++){
				if(freq[i]<=freq[j]){
					count=count+freq[i];
				}
			}
			maximum=max(maximum,count);
		}
		
		cout<<maximum<<"\n";
		
	}



    return 0;
}