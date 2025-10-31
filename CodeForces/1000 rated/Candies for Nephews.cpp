#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
    	
    	int n;
    	cin>>n;
    	if(n%3==0){
    		cout<<0;
		}
		else{
			int x=n%3;
			int extra=3-x;
			cout<<extra;
		}
		cout<<"\n";
	}



    return 0;
}