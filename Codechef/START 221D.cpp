#include <bits/stdc++.h>
using namespace std;

int main() {
	int x,y;
	
	cin>>x>>y;
	
	if(x>=y) cout<<"YES";
	else cout<<"NO";

}


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    
	    int n,a,b;
	    cin>>n>>a>>b;
	    
	    vector<int>nums;
	    int count=0;
	    
	    for(int i=0;i<n;i++){
	        int curr;
	        cin>>curr;
	        nums.push_back(curr);
	    }
	    
	    bool weared=false;
	    for(int i=0;i<n;i++){
	        int temp=nums[i];
	        
	        
	        if(temp<a and !weared){
	            weared=true;
	            count++;
	        }
	        if(temp>b){
	            weared=false;
	        }
	        
	        
	    }
	    cout<<count<<endl;
	}

}


#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	
	cin>>t;
	
	while(t--){
	    
	    int n;
	    cin>>n;
	    
	    string str;
	    cin>>str;
	    map<char,int>mp;
	   bool flag=false;
	    
	    for(auto x:str) mp[x]++;
	    
	    for(auto x:mp){
	        if(x.second>2){ cout<<"NO"<<endl; flag=true; break; }
	    }
	    
	    if(!flag) cout<<"YES"<<endl;
	    
	    
	}

}
#include <bits/stdc++.h>
using namespace std;

int main() {
	// if single digit and even so impossible
	
	// if single digit odd so return 0
	
	//if number is already odd return 0
	
	//even - odd is always odd 
	
	
	// odd - odd is always even 
	
	
	//find odd number in bw because even - odd is always odd
	
	
	
	int t;
	cin>>t;
	
	while(t--){
	    
	    int num;
	    
	    cin>>num;
	    
	    if(num%2!=0){
	        cout<<0<<endl;
	        continue;
	    }
	    
	    if(num<10 and num%2==0){
	        cout<<-1<<endl;
	        continue;
	        
	    }
	    int count=0;
	    bool odd_found=false;
	    
	    while(num>0){ 
	        
	        int maximum=0;
	        
	        ++count;
	        
	        string str=to_string(num);
	        
	        for(auto &x:str){
	            if(( x-'0') %2!=0 ){   //find odd
	                odd_found=true;
	                break;
	            }
	            maximum=max(maximum,x-'0');
	        }
	        
	        if(odd_found) break;
	        
	        num=num-maximum;
	    }
	    
	    if(odd_found) cout<<count<<endl;
	    
	    else cout<<-1<<endl;
	    
	    
	    
	    
	}
	
	
	

}
