class NumArray {
public:
vector<int>tree;
int n;
    NumArray(vector<int>& nums) {
         n=nums.size();
        tree.resize(4*n);
        build(0,0,nums.size()-1,nums);
    }

    void build(int i,int left,int right,vector<int>& nums){
        if(left==right){
            tree[i]=nums[left];
            return;
        }

        int mid=(left+right)/2;

        build(2*i+1,left,mid,nums);
        build(2*i+2,mid+1,right,nums);
        tree[i]=tree[2*i+1]+tree[2*i+2];
    }

    void updateHelper(int i,int left,int right,int pos,int val){
        if(left==right){
            tree[i]=val;
            return;
        }

        int mid=(left+right)/2;

        if(pos<=mid)
            updateHelper(2*i+1,left,mid,pos,val);
        else
            updateHelper(2*i+2,mid+1,right,pos,val);

        tree[i]=tree[2*i+1]+tree[2*i+2];
    }
    
    void update(int index, int val){
        updateHelper(0,0,n-1,index,val);
        
    }
    int query(int i, int l, int r, int ql, int qr) {

    if(r<ql or l>qr)
        return 0;

    if(ql<=l and r<=qr)
        return tree[i];
    int mid=(l+r)/2;

    int leftSum=query(2*i+1,l,mid,ql,qr);
    int rightSum=query(2*i+2,mid+1,r,ql,qr);

    return leftSum+rightSum;
}
    
    int sumRange(int left, int right) {

        return query(0,0,n-1,left,right);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
