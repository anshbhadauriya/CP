#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    
    while(t--){
    	int n1,n2;
		cin>>n1>>n2;
		string a,b;
		cin>>a>>b;
		int count=0;
		bool flag=false;
	for(int i=0;i<6;i++){
		if(a.find(b)!=string::npos){
			cout<<i<<endl;
			flag=true;
			break;
		}
		a=a+a;
	}
	if(!flag){
	cout<<-1<<endl;
}
	
	}



    return 0;
}