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
    long long a;
    cin>>a;
    vector<long long>nums(n);
    for(int i=0;i<n;i++){
    	cin>>nums[i];
	}
	int take_larger=0,take_smaller=0;
	for(int i=0;i<n;i++){
		if(nums[i]>a){
			take_larger++;
		}
		else if (nums[i]<a){
			take_smaller++;
		}
	}
	if(take_larger>=take_smaller){
		cout<<a+1<<endl;
	}
	else{
		cout<<a-1<<endl;
	}
    	
	}



    return 0;
}