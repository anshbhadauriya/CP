Bad for memory approach-> 

  class Solution {
public:
    void solve(int i, int sum,   //isme & <-yeh nhi lagaya curr me mtlb har state ke paas copy hogi khudki too kabhi pop back krne ki zaroort nhi so no backtrack require but the probleme is this will consume so much memory and i will be kicked out from interview
               vector<int> curr,              // passed by value
               vector<vector<int>>& ans,
               vector<int>& nums,
               int target) {

        if (sum == target) {
            ans.push_back(curr);
            return;
        }

        if (i == nums.size() || sum > target)
            return;

        // skip
        solve(i + 1, sum, curr, ans, nums, target);

        // take (reuse allowed)
        curr.push_back(nums[i]);
        solve(i, sum + nums[i], curr, ans, nums, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, 0, curr, ans, nums, target);
        return ans;
    }
};


Memory efficient-> do backtracking and use same vector 

class Solution {
public:
    void solve(int i, int sum,   
               vector<int>& curr,              
               vector<vector<int>>& ans,
               vector<int>& nums,
               int target) {

        if (sum == target) {
            ans.push_back(curr);
            return;
        }

        if (i == nums.size() || sum > target)
            return;

        // skip
        solve(i + 1, sum, curr, ans, nums, target);

        // take (reuse allowed)
        curr.push_back(nums[i]);
        solve(i, sum + nums[i], curr, ans, nums, target);
        curr.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, 0, curr, ans, nums, target);
        return ans;
    }
};
