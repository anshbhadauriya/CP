Q1->
#include <bits/stdc++.h>
using namespace std;

int main() {
	//a-> -1 from A and -2 from B 
	//b-> -1 from B and -3 from C
	
	//agr C is not divisble by 3 then impossible
	
	//then B-(C/3) agr vo result 2 se divisble hai then fine else not
	
	
	int t;
	
	cin>>t;
	
	while(t--){
	    
	    int a,b,c;
	    cin>>a>>b>>c;
	    
	    if(c%3!=0){
	        cout<<"No"<<endl;
	        continue;
	        
	    }
	    
	    b=b-(c/3);
	    c=0;
	    
	    if(b%2!=0){
	        cout<<"No"<<endl;
	        continue;
	    }
	   
	    
	    a=a-(b/2);
	    b=0;
	    
	    if(a==0 and b==0 and c==0){
	        cout<<"Yes"<<endl;
	    }
	    else{
	        cout<<"No"<<endl;
	    }
	}
	return 0;

}

Q2->

  #include <bits/stdc++.h>
using namespace std;

int main() {
	
	
	//N pairs of integers given hai
	
	//ith pair-> a,b 
	
	//b>=a
	
	//try kro inital X to be very large
	
	int t;
	
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    int y=INT_MAX;
	    
	    for(int i=0;i<n;i++){
	        int a,b;
	        cin>>a>>b;
	        
	        if(a>y){
	            y=a;
	        }
	        else if(y>b){
	            y=b;
	        }
	        
	    }
	    
	    cout<<y<<endl;
	}
	return 0;

}
Q3->  
  #include <bits/stdc++.h>
using namespace std;

int main() {
	//  3 index chuno
	
	//all should be distinct
	
	//aur a[i]+a[j]!=a[k] yehhhhh
	
	//2 largest ele ka sum != min ele
	
	
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    vector<pair<int,int>>nums;
	    set<int>st;
	    
	    for(int i=0;i<n;i++){
	        int curr;
	        cin>>curr;
	        nums.push_back({curr,i});
	        st.insert(curr);
	    }
	    if(st.size()==1 and *st.begin()==0){
	        cout<<-1<<endl;
	        continue;
	    }
	    sort(nums.begin(),nums.end());
	    
	    int a=nums.back().first;
	    int b=nums[n-2].first;
	    int c=nums[0].first;
	    
	    if(a+b!=c){
	        
	        cout<<nums.back().second+1<<" ";
	        cout<<nums[n-2].second+1<<" ";
	        cout<<nums[0].second+1;
	        cout<<endl;
	        
	        
	    }
	    else{
	        cout<<-1<<endl;
	    }
	}
	return 0;
	
	

}

