#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    int n;
    cin>>n;
    
    vector<int>result;
    ll count=1;
    
    for(int i=0;i<n;i++){
    	int curr;
    	cin>>curr;
    	result.push_back(curr);
	}
	if(n==1){
		cout<<1;
	}
	else{
	sort(result.begin(),result.end());
	
	for(int i=1;i<n;i++){
		if(result[i]!=result[i-1]) count++;
	}
	cout<<count;	
}

	
	

    return 0;
}