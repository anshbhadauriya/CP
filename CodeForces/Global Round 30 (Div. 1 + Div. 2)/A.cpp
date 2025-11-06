#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
    	
    	int n,x;
    	cin>>n;
    	vector<int>nums(n);
    	for(int i=0;i<n;i++){
    		cin>>nums[i];
		}
		cin>>x;
		if(n==1){
            if(nums[0] == x){
			cout << "YES\n";
		}
            else{
			cout << "NO\n";
		}
            continue;
        }
		bool flag=false;
		for(int i=0;i<nums.size()-1;i++){
			if((nums[i]<=x and nums[i+1]>=x)  or (nums[i]>=x and nums[i+1]<=x)){
				cout<<"YES"<<endl;
				flag=true;
				break;
			}
		}
		if(!flag){
			cout<<"NO"<<endl;
		}
	}

    return 0;
}