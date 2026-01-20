int n;
vector<int> arr;
vector<vector<int>> st;
vector<int> lg;

void build() {
    int LOG = log2(n) + 1;
    st.assign(n, vector<int>(LOG));

    for(int i = 0; i < n; i++)
        st[i][0] = arr[i];

    for(int k = 1; k < LOG; k++) {
        for(int i = 0; i + (1 << k) <= n; i++) {
            st[i][k] = min(
                st[i][k-1],
                st[i + (1 << (k-1))][k-1]
            );
        }
    }

    lg.assign(n+1, 0);
    for(int i = 2; i <= n; i++)
        lg[i] = lg[i/2] + 1;
}

int query(int l, int r) {
    int k = lg[r - l + 1];
    return min(
        st[l][k],
        st[r - (1 << k) + 1][k]
    );
}
