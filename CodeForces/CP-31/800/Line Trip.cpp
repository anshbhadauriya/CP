#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    
    while(t--){
    int n,x;
    cin>>n>>x;
    
    vector<int>nums(n+1);
    nums[0]=0;
    for(int i=1;i<n;i++){
    	cin>>nums[i];
	}
	nums[n]=x;
	int max_diff=0;
	
	for(int i=0;i<n;i++){
		int diff=nums[i+1]-nums[i];
		if(i==n-1){
			diff=diff*2;
		}
		max_diff=max(max_diff,diff);
	}
    cout<<max_diff<<endl;
	}



    return 0;
}