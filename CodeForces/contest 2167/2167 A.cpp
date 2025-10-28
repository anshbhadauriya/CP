#include <iostream>
using namespace std;

int main() {
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin>>t;

    while(t--) {
        int a,b,c,d;
        cin >>a>>b>>c>>d;

     
        if (a==b && b==c && c==d) {
            cout << "YES\n"; 
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}