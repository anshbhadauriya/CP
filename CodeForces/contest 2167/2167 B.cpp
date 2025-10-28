#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--) {
        
        int n; 
        cin>>n;
        
        string a;
        string b;
        cin>>a>>b; 
     
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        if(a==b) {
            cout<< "YES\n";
        } else {
            cout<< "NO\n";
        }
    }
    
    return 0;
}