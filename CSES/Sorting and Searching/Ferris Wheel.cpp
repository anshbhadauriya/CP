#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    int n,limit;
    cin>>n>>limit;
    
    vector<int>nums(n);
    
    for(int i=0;i<n;i++) cin>>nums[i];
    
    sort(nums.begin(),nums.end());
    
   int count=0,i=0,j=n-1;
   
   while(i<=j){
   	if(nums[i]+nums[j]<=limit){
   		i++;  //sabse chote ko sbse bade ke sath pair krdo
   		j--;
	   }
	   else{  //agr weight limit se zyda horha so we have to take larger element alone 
	   	j--;
	   }
	   count++;
   }
	
	cout<<count;
    
 


    return 0;
}