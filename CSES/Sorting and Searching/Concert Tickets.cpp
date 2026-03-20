#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n>>m;
    multiset<int>ms;
    vector<int>tickets(n),customers(m);
    
    for(int i=0;i<n;i++){
    	
    	int curr;
    	cin>>curr;
    	ms.insert(curr);
	}
    
    for(int i=0;i<m;i++) cin>>customers[i];
    
    
    int i=0,j=0;
    
    
   
    for(int i=0;i<m;i++){
    	auto it=ms.upper_bound(customers[i]);
    	
    	if(it==ms.begin()){
    		cout<<-1<<endl;
		}
		else{
			--it;
			cout<<*it<<endl;
			ms.erase(it);
		}
		
	}
	
    
    

    return 0;
}