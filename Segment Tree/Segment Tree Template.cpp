template link-> https://github.com/anshbhadauriya/CP/edit/main/Segment%20Tree/Segment%20Tree%20Template.cpp
I hope you know copying template is not cheating ❤️


vector<int> seg;

/* ---------- BUILD ---------- */
void build(int i, int l, int r, vector<int> &arr) {
    if (l == r) {
        seg[i] = arr[l];
        return;
    }

    int mid = (l + r) / 2;

    build(2*i+1, l, mid, arr);
    build(2*i+2, mid+1, r, arr);

    seg[i] = seg[2*i+1] + seg[2*i+2];
}

/* ---------- QUERY ---------- */
int query(int i, int l, int r, int ql, int qr) {
    // no overlap
    if (r < ql || l > qr) return 0;

    // complete overlap
    if (l >= ql && r <= qr) return seg[i];

    int mid = (l + r) / 2;

    return query(2*i+1, l, mid, ql, qr) +
           query(2*i+2, mid+1, r, ql, qr);
}

/* ---------- UPDATE ---------- */
void update(int i, int l, int r, int pos, int val) {
    if (l == r) {
        seg[i] = val;
        return;
    }

    int mid = (l + r) / 2;

    if (pos <= mid)
        update(2*i+1, l, mid, pos, val);
    else
        update(2*i+2, mid+1, r, pos, val);

    seg[i] = seg[2*i+1] + seg[2*i+2];
}
