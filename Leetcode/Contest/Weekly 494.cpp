Q1-> class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
       return true;
    }
};

Q2->
  class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int even=0,odd=0,minimum=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0) even++;
            else{
                minimum=min(minimum,nums1[i]);
                odd++;
            }
        }

        if(even==nums1.size() or odd==nums1.size()) return true;  //agr sare hi ho

        

        //minimum sbhi even se chota hona chaiye

        for(auto x:nums1){
            if(minimum>x) return false;
            
        }

        return true;

        
        
        
    }
};

Q3->
  class Solution {
public:
    //states rkho curr , xxor
    int solve(int i,int xorr,vector<int>&nums,int &target,vector<vector<int>>&dp){
        if(i==nums.size()){
            if(xorr==target) return 0;

            return 1e9; //agr impossible ho
            //baad me sochna
        }

        if(dp[i][xorr]!=-1) return dp[i][xorr];

        // int take=INT_MAX,skip;

        
            int take=solve(i+1,xorr^nums[i],nums,target,dp);
        
       
            // int take=solve(i+1,xorr^nums[i],nums,target);
        
        int skip=1+solve(i+1,xorr,nums,target,dp);

        return dp[i][xorr]=min(take,skip);
    }
    int minRemovals(vector<int>& nums, int target) {
        vector<vector<int>>dp(nums.size(),vector<int>(16384,-1));

         int ans=solve(0,0,nums,target,dp);
        if(ans>=1e9) return -1;

        return ans;
    }
};
