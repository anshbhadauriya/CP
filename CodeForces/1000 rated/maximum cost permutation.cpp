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
    	int count=0;
    	unordered_set<int>st;
    	vector<int>given(n);
    	for(int i=0;i<n;i++){
    		cin>>given[i];
    		st.insert(given[i]);
		}
		vector<int>ideal;
    	
    	for(int i=1;i<=n;i++){
    		ideal.push_back(i);
		}
		vector<int>desc;
		for(int i=n;i>=0;i--){
			if(!st.count(i)){
			desc.push_back(i);
		}
		}
		int j=0;
		for(int i=0;i<given.size();i++){
			if(given[i]==0){
				given[i]=desc[j];
				j++;
			}
		}
		for(int i=0;i<n;i++){
			if(given[i]!=ideal[i]){
				count++;
			}
		}
		cout<<count;
		cout<<"\n";
		
    	
	}



    return 0;
}