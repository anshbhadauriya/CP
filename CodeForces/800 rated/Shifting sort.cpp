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
    string str(n,' ');
    for(int i=0;i<n;i++){
    	cin>>str[i];
	}
    string clone;
    string sorted;
    int count=0;
    int ones=0,zeros=0;
    for(int i=0;i<n;i++){
    	if(str[i]=='0'){
    		zeros++;
    		clone.push_back('1');
		}
		else{
			ones++;
			clone.push_back('0');
		}
	}
	for(int i=0;i<zeros;i++){
		sorted.push_back('0');
	}
	for(int i=0;i<ones;i++){
		sorted.push_back('1');
	}
	for(int i=0;i<n;i++){
		if(sorted[i]=='1' and sorted[i]==clone[i]){
			count++;
		}
	}
	
	cout<<count<<endl;
	
	}



    return 0;
}