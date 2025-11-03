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
    	int temp=INT_MAX;
    	vector<int>result;
    	for(int i=0;i<n;i++){
    		int a;
    		cin>>a;
    		if(a>temp){	
    			result.push_back(i+1);
			}
    		temp=min(temp,a);
		}
		cout<<result.size()<<endl;
		for(int i=0;i<result.size();i++){
			cout<<result[i]<<" ";
		}
		cout<<endl;
		
	}



    return 0;
}