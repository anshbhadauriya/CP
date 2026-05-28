class Solution {
public:
/*
Easyyy
Just remember ki kabhi bhi exact K/Goal/Size etc.. dia ho sliding window ke question me
so we have to find <=K then <k then <=k - <k  ->  (==k) we do this bcs its so hard to find ==k directy 
*/

int solve(vector<int>&nums,int goal){

    int l=0,h=0,sum=0,result=0;

    while(h<nums.size()){
        sum+=nums[h];

        while(sum>goal and l<=h){
            sum-=nums[l];
            l++;
        }

        result+=(h-l+1);  //added subarray length bcs all ele can make a subarray with new ele
        h++;
    }

    return result;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {


        int a=solve(nums,goal);
        int b=solve(nums,goal-1);

        return a-b;
        
    }
};
