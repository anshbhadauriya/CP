class Solution {
public:

vector<int>dp;

int solve(int i,vector<int>&nums,int &target){

    if(i==nums.size()-1){
        return 0;
    }

    if(dp[i]!=-2) return dp[i];

    int ans=-1;

    for(int j=i+1;j<nums.size();j++){
        if(abs(nums[j]-nums[i])<=target){
        int temp=solve(j,nums,target);  //pre check

        if(temp!=-1) ans=max(ans,1+temp); //check kro ki state valid hai ya nhi

        }
    }

    return dp[i]=ans;  //agr -1 hai ans too invalid 

}
    int maximumJumps(vector<int>& nums, int target) {

        dp.resize(nums.size(),-2);

        return solve(0,nums,target);
        
    }
};
