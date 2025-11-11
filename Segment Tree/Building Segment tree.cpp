 void build(int index, int left, int right, vector<int>& arr) {
        if (left == right) {
            tree[index] = arr[left]; // leaf node
            return;
        }

        int mid = (left + right) / 2;

        // build left and right subtrees
        build(2 * index + 1, left, mid, arr);
        build(2 * index + 2, mid + 1, right, arr);

        // internal node = sum of children
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }