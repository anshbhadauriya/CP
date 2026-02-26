#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int sizee;
vector<ll>seg;

void build(int i,int left,int right,vector<int>&nums){
	if(left==right){
		seg[i]=nums[left];
		return;
	}
	
	int mid=left+(right-left)/2;
	build(2*i+1,left,mid,nums);
	build(2*i+2,mid+1,right,nums);
	seg[i]=seg[2*i+1]+seg[2*i+2];
}

ll sum_query(int i,int left,int right,int ql,int qr){
	if(right<ql or left>qr) return 0;
	
	if(ql<=left and right<=qr) return seg[i];
	
	int mid=left+(right-left)/2;
	
	ll leftsum=sum_query(2*i+1,left,mid,ql,qr);
	ll rightsum=sum_query(2*i+2,mid+1,right,ql,qr);
	
	return leftsum+rightsum;
}

void update(int i,int left,int right,int pos,int newValue){
	if(left==right){
		seg[i]=newValue;
		return;
	}
	int mid=left+(right-left)/2;
	
	if(pos<=mid)
            update(2*i+1,left,mid,pos,newValue);
        else
            update(2*i+2,mid+1,right,pos,newValue);

        seg[i]=seg[2*i+1]+seg[2*i+2];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,q; 
	cin>>n>>q;
	
	vector<int>nums(n);
	for(int i=0;i<n;i++) cin>>nums[i];
	
	vector<vector<int>>queries;
	
	for(int i=0;i<q;i++){
		int type,a,b;
		cin>>type>>a>>b;
		queries.push_back({type,a,b});
	}
	 sizee=n;
	seg.resize(4*n,0);
	
	build(0,0,n-1,nums);
	
	for(int i=0;i<q;i++){
		int type=queries[i][0];
		if(type==1){
			int pos=queries[i][1]-1;
			int val=queries[i][2];
			update(0,0,n-1,pos,val);
		}
		else{
			int l=queries[i][1]-1;
			int r=queries[i][2]-1;
			
			cout<<sum_query(0,0,n-1,l,r)<<endl;
			
		}
	}
	
	return 0;
	
}