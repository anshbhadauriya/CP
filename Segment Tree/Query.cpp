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
