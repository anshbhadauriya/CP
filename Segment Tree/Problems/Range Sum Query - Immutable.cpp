class NumArray {
public:
vector<int>tree;
int n;
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

int query(int i,int left,int right,int ql,int qr){

    if(right<ql or left>qr) return 0;

    if(ql<=left and right<=qr){
        return tree[i];
    }

    int mid=(left+right)/2;

    int leftsum=query(2*i+1,left,mid,ql,qr);
    int rightsum=query(2*i+2,mid+1,right,ql,qr);

    return leftsum+rightsum;
}



    NumArray(vector<int>& nums) {
        n=nums.size();
        tree.resize(4*n);
        build(0,0,n-1,nums);
    }
    
    int sumRange(int left, int right) {

        return query(0,0,n-1,left,right);
        
    }
};

