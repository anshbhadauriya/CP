Q1->

  #include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    int x,y,n;
	    
	    cin>>x>>y>>n;
	    
	    int ans=x-(y*n);
	    if(ans<=0) cout<<0<<endl;
	    else cout<<ans<<endl;
	}
	
	
return 0;
}


Q2->

  #include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    
	    int n,a,b;
	    cin>>n>>a>>b;
	    
	    if(n<a){
	   cout<<n<<endl;
	    continue; }
	    
	    
	    int sub=a-b;
	    int count=0;
	    
	   int diff=a-b;
        cout<<b+(n-a)%diff << endl;
	   
	    
	    
	    
	}
	return 0;

}


Q3->

  #include <bits/stdc++.h>
using namespace std;

int main() {
	//kisi tarah freq count kro minimum fir decrease kro
	
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    vector<int>nums;
	    int k;
	    cin>>n>>k;
	    
	    map<int,int>mp;
	    
	    for(int i=0;i<n;i++){
	        int curr;
	        cin>>curr;
	        nums.push_back(curr);
	        mp[curr]++;
	    }
	    int first_freq=mp[nums.front()];
	    mp.erase(nums.front());
	    vector<int>freq;
	    for(auto x:mp){
	        freq.push_back(x.second);
	    }
	    
	    sort(freq.begin(),freq.end());
	    int i=0;
	    
	    while(k>0 and i<freq.size()){
	        
	        if(freq[i]<=k){
	            k-=freq[i];
	            freq[i]=0;
	            i++;
	        }
	        else break;
	        
	        
	        
	    }
	    
	    int sum=0;
	    for(int i=0;i<freq.size();i++){
	    if(freq[i]>0) sum+=1;
	    }
	    
	    sum+=1;
	    
	    
	    cout<<sum<<endl;
	    
	    
	}
	return 0;
	
	

}
