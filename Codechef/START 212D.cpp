#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    
	    int n;
	    cin>>n;
	    vector<int>nums(n);
	    priority_queue<pair<int,int>>pq;
	    for(int i=0;i<n;i++){
	        int a;
	        cin>>a;
	        nums[i]=a;
	        pq.push({a,i});
	       
	    }
	    
	    
	    
	    int total=0;
	    while(!pq.empty()){
	        
	        int maximum=pq.top().first;
	        int idx=pq.top().second;
	        pq.pop();
	        
	        
	        int left =count_if(nums.begin(),nums.begin()+idx,[](int x){ 
			return x!=0; 
			});
			int right=count_if(nums.begin()+idx+1,nums.end(),[](int x){ 
			return x!=0;
			 });

	        nums[idx]=0;
	        
	        total=total+min(left,right);
	        
	        
	        
	    }
	    
	    cout<<total<<endl;
	    
	    
	    
	    
	    
	}

}
