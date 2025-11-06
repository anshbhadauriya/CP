#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int>odd,even;
        
        for(int i=0;i<n;i++) {
            int a;
            cin>>a;
            if (a % 2 == 0) {
                even.push_back(a);
            } else {
                odd.push_back(a);
            }
        }
        
        bool found=false;

        if(even.size()>=2) {
            cout<<even[0]<<" "<<even[1]<<endl;
            found=true;
        } 
        
        else if(!odd.empty() && odd[0]==1) {
            if(odd.size()>=2){
                cout<<odd[0] <<" "<<odd[1]<<endl; 
            } else {
                cout<<odd[0]<<" "<<even[0] << endl; 
            }
            found=true;
        }
        
        else if(odd.size()>=2) {
            int x=odd[0];
            for(int i=1;i<odd.size();i++) {
                int y=odd[i];
                if(y%x%2==0) {
                    cout<<x <<" "<<y<<endl;
                    found=true;
                    break; 
                }
            }
        }
        
        if(!found){
            cout<<-1<<endl;
        }
    }

    return 0;
}