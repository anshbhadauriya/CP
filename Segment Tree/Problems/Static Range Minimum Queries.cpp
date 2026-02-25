#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void build(int i,int l,int r,vector<int>&nums,vector<int>&seg){
    if(l==r){
        seg[i]=nums[l];
        return;	
    }
	
    int mid=l+(r-l)/2;
	
    build(2*i,l,mid,nums,seg);
    build(2*i+1,mid+1,r,nums,seg);
    seg[i]=min(seg[2*i],seg[2*i+1]);
}

int query(int i,int l,int r,int ql,int qr,vector<int>&seg){
    if(r<ql or l>qr) return INT_MAX;
	
    if(ql<=l and r<=qr) return seg[i];
	
    int mid=l+(r-l)/2;
	
    int lmin=query(2*i,l,mid,ql,qr,seg);
    int rmin=query(2*i+1,mid+1,r,ql,qr,seg);
	
    return min(lmin,rmin);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,q;
    cin>>n>>q;
  
    vector<int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
  
    vector<int>seg(4*n+1);
  
    build(1,0,n-1,nums,seg);
  
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        l--; r--;     // if input is 1-indexed
        
        cout<<query(1,0,n-1,l,r,seg)<<endl;
    }

    return 0;
}
