int query(int i, int l, int r, int ql, int qr) {

    // ❌ No overlap
    if (r < ql || l > qr)
        return 0;

    // ✅ Complete overlap
    if (ql <= l && r <= qr)
        return tree[i];

    // ⚡ Partial overlap
    int mid = (l + r) / 2;

    int leftSum = query(2*i+1, l, mid, ql, qr);
    int rightSum = query(2*i+2, mid+1, r, ql, qr);

    return leftSum + rightSum;
}






if you used lazy propogation then:-

    int query(int i, int l, int r, int ql, int qr) {

    if(lazyTree[i]!=0){
        tree[i]+=(right-left+1)*lazyTree[i];

        if(left!=right){
            lazyTree[2*i+1]+=lazyTree[i];
            lazyTree[2*i+2]+=lazyTree[i];
        }
        lazyTree[i]=0;
    }

    // ❌ No overlap
    if (r < ql || l > qr)
        return 0;

    // ✅ Complete overlap
    if (ql <= l && r <= qr)
        return tree[i];

    // ⚡ Partial overlap
    int mid = (l + r) / 2;

    int leftSum = query(2*i+1, l, mid, ql, qr);
    int rightSum = query(2*i+2, mid+1, r, ql, qr);

    return leftSum + rightSum;
}

    
