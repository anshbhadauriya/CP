#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    
    while(t--){
    	int x1,y1,x2,y2;
    	cin>>x1>>y1>>x2>>y2;
    	
    	if(y1>y2 or x2-x1>y2-y1){
    		cout<<-1<<endl;
		}
		
		else{
			
			int operations=y2-y1;  //y tak pohochne ke operations
			int temp_x=x1+(y2-y1);  //y take pohochkr x ki new value aai
			operations+=temp_x-x2;   //x ki new value se target x tak pohochne ki distance
			cout<<operations<<endl;
		}
		
		
		
	
	}



    return 0;
}