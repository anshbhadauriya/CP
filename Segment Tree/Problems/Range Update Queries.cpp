#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int sizee;
vector<ll>seg,lazyTree;

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

void updateRange(int start, int end, int i, int l, int r, int val) {
    if (lazyTree[i] != 0) {
        seg[i] += (r - l + 1) * lazyTree[i];
      
        if (l != r) { //Not a leaf node
            lazyTree[i * 2 + 1] += lazyTree[i]; //Left Child in Lazy Tree
            lazyTree[i * 2 + 2] += lazyTree[i]; //Right Child in Lazy tree
        }
        lazyTree[i] = 0;
    }

    //Invalid or out of range
    if (l > end || r < start || l > r)
        return;

    //[start...end[ is Exactly withing range of current nod [l..r]
    if (l >= start && r <= end) {
        seg[i] += (r - l + 1) * val;
        if (l != r) {
            lazyTree[i * 2 + 1] += val;
            lazyTree[i * 2 + 2] += val;
        }
        return;
    }

    //Call for left and right subtree
    int mid = (l + r) / 2;
    updateRange(start, end, 2*i+1, l, mid, val);
    updateRange(start, end, 2*i+2, mid+1, r, val);
    seg[i] = seg[i * 2 + 1] + seg[i * 2 + 2];
}

ll sum_query(int i,int left,int right,int ql,int qr){
	if(lazyTree[i]!=0){
        seg[i]+=(right-left+1)*lazyTree[i];

        if(left!=right){
            lazyTree[2*i+1]+=lazyTree[i];
            lazyTree[2*i+2]+=lazyTree[i];
        }
        lazyTree[i]=0;
    }
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
		int type;
		cin>>type;
		if(type==1){
			int a,b,u;
			cin>>a>>b>>u;
			queries.push_back({type,a,b,u});
		}
		else{
			int b;
			cin>>b;
			queries.push_back({type,b});
		}
	}
	 sizee=n;
	seg.resize(4*n,0);
	lazyTree.resize(4*n,0);
	
	build(0,0,n-1,nums);
	
	for(int i=0;i<q;i++){
		int type=queries[i][0];
		if(type==1){
			int l=queries[i][1]-1;
			int r=queries[i][2]-1;
			int val=queries[i][3];
			updateRange(l,r,0,0,n-1,val);;
		}
		else{
			int k=queries[i][1];
			cout<<sum_query(0,0,n-1,k-1,k-1)<<endl;
			
		}
	}
	
	return 0;
	
}