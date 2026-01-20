#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    
    ll n,q;
    cin>>n>>q;
    vector<ll>nums(n,0),prefix(n,0);
    ll sum=0;
    
    for(int i=0;i<n;i++){
    	ll curr;
    	cin>>curr;
    	sum+=curr;
    	nums[i]=curr;
    	prefix[i]=sum;
	}
	
	while(q--){
		
		ll start,end;
		
		cin>>start>>end;
		
		start-=1;
		end-=1;
		
		if(start==0){
			cout<<prefix[end]<<endl; continue;
		}

		
		cout<<prefix[end]-prefix[start-1]<<endl;
	} 


    return 0;
}