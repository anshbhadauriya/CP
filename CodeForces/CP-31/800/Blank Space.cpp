#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n; cin>>n;
        int prev=-1;
        int maximum=0;
        int count=0;
        for(int i=0;i<n;i++){
        	int curr; cin>>curr;
        	if(prev==-1){
        		prev=curr;
        		if(prev==0) ++count;
        		maximum=max(maximum,count);
        		continue;
			}
			if(prev==0 and curr==0){
				++count;
				maximum=max(maximum,count);
				continue;
			}
			if(prev==0 and curr==1){
				count=0;
				continue;
			}
			if(prev==1 and curr==0){
				prev=0;
				++count;
				maximum=max(maximum,count);
			}
			
		}
		cout<<maximum<<endl;
    }

    return 0;
}
