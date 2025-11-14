#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    int minimum=INT_MAX;
    for(int i=0;i<n;i++){
    	int a;
    	cin>>a;
    	if(a<0){
    		a=a*-1;
		}
    	if(a<minimum){
    		minimum=a;
		}
	}
	if(minimum<0){
		cout<<-1*minimum;
	}
	else{
		cout<<abs(minimum);
	}
	



    return 0;
}