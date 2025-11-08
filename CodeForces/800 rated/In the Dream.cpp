#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    
    while(t--){
    	int a1,b1,a2,b2;
    	cin>>a1>>b1>>a2>>b2;
    	
    	int maxx1=max(a1,b1);
    	int minn1=min(a1,b1);
    	
    	int ideal=(maxx1-1)/2;
    	if(minn1<ideal){
    		cout<<"NO"<<endl;
    		continue;
		}
		
		int new_a=a2-a1;
		int new_b=b2-b1;
		
		int maxx2=max(new_a,new_b);
		int minn2=min(new_a,new_b);
		int new_ideal=(maxx2-1)/2;
		
		if(minn2<new_ideal){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		
	}



    return 0;
}