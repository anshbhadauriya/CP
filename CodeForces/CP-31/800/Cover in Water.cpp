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
    	string nums;
    	cin>>nums;
		int consecutive=1,dots=0;
		int maximum=0;
		for(int i=0;i<n-1;i++){
			if(nums[i]=='.' and nums[i]==nums[i+1]){
				consecutive++;
			}
			else{
				consecutive=1;
			}
			maximum=max(maximum,consecutive);
		}
		for(int i=0;i<n;i++){
			if(nums[i]=='.'){
				dots++;
			}
		}
		if(maximum>=3){
			cout<<2<<endl;
		}
		else{
			cout<<dots<<endl;
		}
		
	}



    return 0;
}