#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t;
    cin>>t;
    cin.ignore();
    while(t--){
    	string str;
    	string ans;
    	getline(cin, str);
    	for(int i=0;i<str.size();i++){
    		if(i==0 and str[i]!=' '){
    			ans=ans+str[i];
			}
			if(i+1<str.size() and str[i]==' ' and str[i+1]!=' '){
				ans.push_back(str[i+1]);
			}
			
		}
		cout<<ans<<"\n";
    	
	}



    return 0;
}