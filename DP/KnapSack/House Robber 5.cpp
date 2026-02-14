class Solution {
public:
    long long solve(int i,vector<int>&nums,vector<int>&colors,bool prev,vector<vector<long long>>&dp){
        if(i==nums.size()) return 0;

        if(dp[i][prev]!=-1) return dp[i][prev];
        
            if(!prev or (prev and colors[i]!=colors[i-1])){  //yaa too first element nhi lia ho yaa too first element lia and first != second 
             long long take=nums[i]+solve(i+1,nums,colors,true,dp);
            long long skip=solve(i+1,nums,colors,false,dp);
            return dp[i][prev]=max(take,skip);
        }

        else{
            return dp[i][prev]=solve(i+1,nums,colors,false,dp);
        }

        

        
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        vector<vector<long long>>dp(nums.size(),vector<long long>(2,-1));
        return solve(0,nums,colors,false,dp);
    }
};
