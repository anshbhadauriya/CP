Q1->
  #include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	
	while(t--){
	    int a,b,c;
	    cin>>a>>b>>c;
	    int count=0;
	    
	    if(a>=50) count++;
	    if(b>=50) count++;
	    if(c>=50) count++;
	    if(count>=2) cout<<"Yes"<<endl;
	    else cout<<"No"<<endl;
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
	    int n,k;
	    cin>>n>>k;
	    
	    vector<int>nums(n);
	    for(int i=0;i<n;i++) cin>>nums[i];
	    
	    
	    int a=5*k;
	   // int buy=a+b;
	   
	   int profit=0;
	    
	    sort(nums.rbegin(),nums.rend());
	    for(int i=0;i<k;i++){
            if(nums[i]>5) {
                profit+=nums[i]-5;
            }
        }
        
        for(int i=k;i<n;i++) {
            if(nums[i]>10) {
                profit+=nums[i]-10;
            }
        }

        cout<<profit<<endl;

	    
	    
	}

}
Q3->

  #include <bits/stdc++.h>
using namespace std;

int main() {
    
    //s is empty
    
    // for each i check if x is presnt in s and x-p[i]<=k
    
    //array B ke koi index par element 1 hai too vo index+1 element s me hona chaiye and if element 0 so vo nhi hona chaiye
    
    int t;
    cin>>t;
    
    while(t--){
    
    int n,k;
    cin>>n>>k;
    vector<int>b(n);
    vector<int>s;
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(b[i]==1) s.push_back(i+1);
    }
    
    if(s.empty()){
    cout<<"No"<<endl;
    continue;
    }
    
    //s ke andr koi 2 ele k distance ke andr nhi hone chaiye
    bool f=false;
    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size();j++){
            if(abs(s[i]-s[j])<=k){
                cout<<"No"<<endl;
                f=true;
                break;
            }
        }
        if(f) break;
    }
    if(f) continue;
    
    //har ele jo s me nhi hai must be with in k of atleast one ele in s
    
    bool possible=true;
    
    for(int i=0;i<n;i++){
        if(b[i]==0){
            int val=i+1;  //curr ele
            bool found=false;
            
            for(auto x:s){
                if(abs(x-val)<=k){
                    found=true;
                    break;
                }
            }
            if(!found){
                possible=false;
                break;
            }
        }
    }
    
    if(possible){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
    
    }
    
    return 0;
    
	
	
	

}
