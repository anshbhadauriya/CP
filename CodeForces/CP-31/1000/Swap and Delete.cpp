#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;
        int zero=0,one=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') zero++;
            else one++;
        }
        int i=0;
        for(i=0;i<s.size();i++){
        	if(s[i]=='0'){
        		if(one){
        		one--;
        	}
        	else{
        		break;
			}
			}
			
			else{
				
				if(zero){
					zero--;
				}
				else{
					break;
				}
			}
		}
		cout<<s.size()-i<<endl;
    }

    return 0;
}