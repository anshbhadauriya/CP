int upperBound(const vector<int>& nums, int target) {
    int l = 0, h = nums.size() - 1;
    int ans = nums.size();
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (nums[mid] > target) {
            ans = mid; 
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    return ans;

}


inbuild cpp function-
    example-
vector<int> nums = {1, 3, 3, 5, 7};
    int target = 3;

    auto it = upper_bound(nums.begin(), nums.end(), target);
    int index = it - nums.begin();  // convert iterator to index

    cout << "Upper bound index: " << index << endl; // 3

