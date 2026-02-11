Q1->
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int x;
	cin>>x;
	int a=100+(x*4);
	cout<<min(300,a);
	
	return 0;

}
Q2->
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>result;
	    int odd=0;
	    for(int i=0;i<n;i++){
	        int curr;
	        cin>>curr;
	        if(curr%2!=0) odd++;
	        result.push_back(curr);
	    }
	    
	    if(odd%2==0){
	        cout<<"Yes"<<endl;
	    }
	    else{
	        cout<<"No"<<endl;
	    }
	    
	   
	}
	return 0;

}

Q3->

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	//if win so coins+=a[i] if lose coins+=b[i]
	
	//waha loose kro jaha a[i]-b[i] minimum ho
	
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>win,loose;
	    for(int i=0;i<n;i++){
	        int curr;
	        cin>>curr;
	        win.push_back(curr);
	    }
	    for(int i=0;i<n;i++){
	        int curr;
	        cin>>curr;
	        loose.push_back(curr);
	    }
	    if(n==1){
	        cout<<loose.front()<<endl;
	        continue;
	    }
	    
	    int idx=-1;
	    int minimum=INT_MAX;
	    
	    for(int i=0;i<n;i++){   //minimum diff find kro
	        int diff=abs(win[i]-loose[i]);
	        if(diff<minimum){
	            minimum=diff;
	            idx=i;
	        }
	    }
	    
	    int count=0;
	    
	    for(int i=0;i<n;i++){
	        if(i==idx){
	            count+=loose[i];
	        }
	        else{
	            count+=win[i];
	        }
	    }
	    cout<<count<<endl;
	    
	    
	}
	return 0;

}

