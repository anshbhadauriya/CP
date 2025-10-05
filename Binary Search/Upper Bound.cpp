int upperBound(const vector<int>& nums, int target) {
    int l = 0, h = nums.size() - 1;
    int ans = nums.size();  // default: if target >= all elements
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (nums[mid] <= target) {
            l = mid + 1;    // search right half
        } else {
            ans = mid;      // potential upper bound
            h = mid - 1;    // search left half
        }
    }
    return ans;
}