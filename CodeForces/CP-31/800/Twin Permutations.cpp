#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    
    while(t--){
    	int n; cin>>n;
    	
    	vector<int>nums;
    	
    	for(int i=0;i<n;i++){
    		int curr;
    		cin>>curr;
    		nums.push_back(curr);
		}
		
		vector<int>ans(n,0);
		
		
		for(int i=0;i<ans.size();i++){  //n+1 isslie taki given numbers ke andr hi rhe 
			ans[i]=n+1-nums[i];  //first i was trying nums[i-1]+ans[i-1]=p[i]+ans[i]  
			                     //so ans[i]=nums[i-1]+ans[i-1]-nums[i]  but answer was going out of n numbers so you have to do n+1-nums[i]
		}
	
	
	
		for(int i=0;i<ans.size();i++){   //print
			cout<<ans[i];
			
			if(i==ans.size()-1) cout<<endl;
			else cout<<" ";
		}
		
	}



    return 0;
}