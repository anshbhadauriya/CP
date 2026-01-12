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
    
    vector<int>nums(n),b,c;
    int maximum=-1;
    
    for(int i=0;i<n;i++){
    	cin>>nums[i];
    	maximum=max(maximum,nums[i]);
	}
	
	for(int i=0;i<n;i++){
		if(nums[i]==maximum){
			c.push_back(nums[i]);
		}
		else{
			b.push_back(nums[i]);
		}
	}
	if(c.empty() or b.empty()){
	cout<<-1<<endl;
	continue;
}
	
	cout<<b.size()<<" "<<c.size()<<endl;
	
	for(int i=0;i<b.size();i++) {
		cout<<b[i];
		if(i==b.size()-1) cout<<endl;
		else{
			cout<<" ";
		}
	}
	for(int i=0;i<c.size();i++) {
		cout<<c[i];

		if(i!=c.size()-1) cout<<" ";
		else cout<<endl;
	}
	
	}



    return 0;
}