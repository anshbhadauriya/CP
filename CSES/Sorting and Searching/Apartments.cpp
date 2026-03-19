#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
   int n,m,k;
   
   cin>>n>>m>>k;
   
   vector<int>nums(n),depts(m);
   
   for(int i=0;i<n;i++) cin>>nums[i];
   
   for(int i=0;i<m;i++) cin>>depts[i];
   
   sort(nums.begin(),nums.end());
   sort(depts.begin(),depts.end());
   
   int i=0,j=0,count=0;
   
   while(i<n and j<m){
   	if(depts[j]>=nums[i]-k and depts[j]<=nums[i]+k){
   		i++;
   		j++;
   		count++;
	   }
	   else if(nums[i]<depts[j]){
	   	i++;
	   }
	   else{
	   	j++;
	   }
	   
   }
   cout<<count;
   

    return 0;
}