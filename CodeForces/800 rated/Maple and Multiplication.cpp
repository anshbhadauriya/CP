#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		if(a==b){
			cout<<0<<endl;
			continue;
			
		}
		else if(a%b==0 or b%a==0){
			cout<<1<<endl;
			continue;
		}
		else{
			cout<<2<<endl;
			continue;
		}
		
		
	}



    return 0;
}