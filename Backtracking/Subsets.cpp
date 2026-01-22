class Solution {
public:

void solve(int i,vector<int>curr,vector<vector<int>>&ans,vector<int>& nums,int n){
    if(i==n){
        ans.push_back(curr);
        return;
    }
    curr.push_back(nums[i]);
    solve(i+1,curr,ans,nums,n);
    curr.pop_back();
    solve(i+1,curr,ans,nums,n);
    
}
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int>curr;
        vector<vector<int>>ans;
        int n=nums.size();

        solve(0,curr,ans,nums,n);

        return ans;


        
    }
};