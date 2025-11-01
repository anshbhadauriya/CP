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
		bool flag=false;
		
		for(int i=0;i<n-1;i++){
			int s1=accumulate(nums.begin(),nums.begin()+i+1,0);
			
			for(int j=i+1;j<n-1;j++){
				int s2=accumulate(nums.begin()+i+1,nums.begin()+j+1,0);
				int s3=accumulate(nums.begin()+j+1,nums.end(),0);
				int a=s1%3,b=s2%3,c=s3%3;
				if((a==b and b==c and a==c)  or (a!=b and b!=c and c!=a)){
					cout<<i+1<<" "<<j+1<<endl;
					flag=true;
					break;
				}
				
				
			}
			if(flag){
					break;
				}
		}
		if(!flag){
			cout<<0<<" "<<0<<endl;
		}
		
		
	}



    return 0;
}