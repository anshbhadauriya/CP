#include<bits/stdc++.h>

using namespace std;

int main(){
	
	vector<int>nums{1,2,3,4,5,6,7,7,7,5,4};
	
	int odd=0,even=0,maximum=0;
	unordered_map<int,int>mp;
	mp[0]=-1;
	
	
	for(int i=0;i<nums.size();i++){
		if(nums[i]%2==0){
			even++;
		}
		else{
			odd++;
		}
		int diff=odd-even;
		
		if(mp.find(diff)!=mp.end()){
			maximum=max(maximum,i-mp[diff]);
		}
		else{
			mp[diff]=i;
		}
		
		
		
	}
	cout<<maximum;
	
	return 0;
	
	
}
