#include<bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(false);
cin.tie(NULL);

int t;
cin>>t;

while(t--){
int n,m;
cin>>n>>m;

vector<long long>a(n);
for(auto&x:a)cin>>x;

priority_queue<long long>pq;
long long sum=0,ans=LLONG_MIN;

for(int i=0;i<m-1;i++){
pq.push(a[i]);
sum+=a[i];
}

for(int i=m-1;i<n;i++){
ans=max(ans,1LL*m*a[i]-sum);

pq.push(a[i]);
sum+=a[i];

if(pq.size()>m-1){
sum-=pq.top();
pq.pop();
}
}

cout<<ans<<'\n';
}
}