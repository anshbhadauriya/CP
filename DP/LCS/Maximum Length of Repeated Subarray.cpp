class Solution {
public:

/*
LCS pattern question.

Difference from LCS:

In LCS:
if(nums1[i-1] != nums2[j-1])
    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

because we are allowed to skip elements
(subsequence).

Here:
if(nums1[i-1] != nums2[j-1])
    dp[i][j] = 0;

because a common subarray must be contiguous.
A mismatch breaks the current matching chain.

dp[i][j] = length of longest common subarray
ending at nums1[i-1] and nums2[j-1].

TC: O(n * m)
SC: O(n * m)
*/
    int findLength(vector<int>& nums1, vector<int>& nums2) {

        int n=nums1.size(),m=nums2.size();

        int maximum=0;

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1])
                dp[i][j]=1+dp[i-1][j-1];

                maximum=max(maximum,dp[i][j]);
            }
        }

        return maximum;


        
    }
};
