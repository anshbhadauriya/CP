#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin>>t;

    while (t--) {
     int n;
     int odd_count=0;
     cin>>n;
     vector<int>toys(n);
     for(int i=0;i<n;i++){
     	cin>>toys[i];
     	if(toys[i]%2!=0){
     		odd_count++;
		 }
	 }
	 
	 if(odd_count==0 || odd_count==n){
	 	for(int i=0;i<n;i++){
	 		cout<<toys[i];
	 		if(i!=n-1){
	 			cout<<" ";
			 }
		 }
	 }
	 else{
	 	sort(toys.begin(),toys.end());
	 	for(int i=0;i<n;i++){
	 		cout<<toys[i];
	 		if(i!=n-1){
	 			cout<<" ";
			 }
		 }
	 	
	 }
	 cout<<"\n";
    }

    return 0;
}