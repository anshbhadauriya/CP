class Solution {
public:


    int solve(int i,int j,vector<int>& nums1,vector<int>& nums2,vector<vector<int>>&dp){

        if(i==nums1.size() or j==nums2.size()){
            return -1e9;   // very small number (because subsequence cannot be empty)

            //smallest value return kar rhe so it will never be taken bcs of this:
            //max(0,solve(i+1,j+1,nums1,nums2,dp) it will always give 0 instead of -ve's

            //dry run kr lena ek bar smjh aajaega
        }

        if(dp[i][j]!=INT_MIN) return dp[i][j];

        int take=nums1[i]*nums2[j]+max(0,solve(i+1,j+1,nums1,nums2,dp));

        int skip1=solve(i+1,j,nums1,nums2,dp);

        int skip2=solve(i,j+1,nums1,nums2,dp);

        return dp[i][j]=max({take, skip1, skip2});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MIN));  //we are using INT_MIN instead of -1 bcs -1 can be multiplication of 2 numbers so we used minimum value
        return solve(0,0,nums1,nums2,dp);
    }
};