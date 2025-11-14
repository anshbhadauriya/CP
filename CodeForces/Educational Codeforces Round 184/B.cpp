#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a;
    cin >> a;
    
    while(a--) {
        string b;
        cin>>b;
        int c=b.length(); 

        bool x=false; 
        for (int i=0;i<c-1;i++){
            bool z=(b[i]=='>' || b[i] =='*');
            bool d = (b[i+1]== '<' || b[i+1]=='*');
            
            if(z && d){
                x=true;
                break;
            }
        }

        if(x){
            cout<<-1<<endl;
        } else {
            int e=0; 
            while(e<c && b[e]=='<'){
                e++;
            }

            int f=0; 
            while(f<c-e && b[c-1-f]=='>') {
                f++;
            }

            if(c-e-f==1){
                cout<<1+max(e,f)<<endl;
            } else {
                cout<<max(e,f)<<endl;
            }
        }
    }
    
    return 0;
}
