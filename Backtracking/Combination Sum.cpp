class Solution {
public:
/*
Har recursive call me we have 2 options

take it and stay in same idx

skip and go in next idx

base case will be out of bound and sum>target
*/

vector<vector<int>>result;

void solve(int i,vector<int>&curr,int sum,int &target,vector<int>& candidates){

    if(sum==target){
        result.push_back(curr);
        return;
    }

    if(sum>target) return;

    if(i==candidates.size()) return;

    curr.push_back(candidates[i]);

    solve(i,curr,sum+candidates[i],target,candidates);

    curr.pop_back();

    solve(i+1,curr,sum,target,candidates);
     
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum=0;
        vector<int>curr;

        solve(0,curr,sum,target,candidates);

        return result;

        /*
        TC-> isme target tak subset bnege so uk agr subsets hote too 2^n hota lekin idhr subsets depends upon target and elements in array so if large ele are there only so we can reach target early so 
        O(N^ target/min(candidate)​)

        SC-> O(target/min(candidate)​)

        */
        
    }
};



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
};   watch striver's video for dryrun
