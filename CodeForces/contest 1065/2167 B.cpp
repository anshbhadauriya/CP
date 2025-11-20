#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<long long>a(n);
        for(int i=0;i<n;i++){
		cin>>a[i];
	}

        long long b=0,c=-1,d=-1;

        if(a[0]!=-1 && a[n-1]!=-1){
            b=abs(a[n-1]-a[0]);
            c=a[0];
            d=a[n-1];
        }else{
            b=0;
            if(a[0]!=-1){
                c=a[0];
                d=a[0];
            }else if(a[n-1]!=-1){
                c=a[n-1];
                d=a[n-1];
            }else{
                c=0;
                d=0;
            }
        }

        a[0]=c;
        a[n-1]=d;

        for(int i=1;i<n-1;i++){
            if(a[i]==-1){
			 a[i]=0;
		}
        }

        cout<<b<<"\n";
        for(int i=0;i<n;i++){
            cout<<a[i];
            if(i!=n-1){
			 cout<<" ";
		}
        }
        cout<<"\n";
    }

    return 0;
}
