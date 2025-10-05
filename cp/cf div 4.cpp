#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    
    while(t>0){
	int a,b;
	cin>>a;
    cin>>b;
    if(b%2==0){
        cout<<0<< "\n";;
    }
    else{
        cout<<a<< "\n";;
    }
    t--;
}
    return 0;
}