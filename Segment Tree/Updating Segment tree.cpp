 void update(int index, int left, int right, int pos, int newValue) {
        if (left == right) {
            tree[index] = newValue;
            return;
        }

        int mid = (left + right) / 2;

        if (pos <= mid)
            update(2 * index + 1, left, mid, pos, newValue);
        else
            update(2 * index + 2, mid + 1, right, pos, newValue);

        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }