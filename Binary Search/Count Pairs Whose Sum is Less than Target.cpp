class Solution {
public:
    int countPairs(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());

        int n=nums.size();
        
        int l=0,h=n-1;

        // for(auto x:nums) cout<<x<<" ";
        // cout<<endl;

        

        /*
        so dekho abh

        nums[i] + x < target

        x < target + nums[i]

        for example:

        -1 1 1 2 3

        ans = tagret + nums[i]

        2 - 1 = 1

        so find max pos so find upper bound 
        
        */

        int result=0;

        for(int i=0;i<n;i++){
            int curr=nums[i];
            int ans=target-nums[i]-1;

            int idx=upper_bound(nums.begin(),nums.end(),ans)-nums.begin() -1;

            // cout<<i<<" ith ans is "<<ans<<endl;
            // cout<<i<<" ith idx is"<<idx<<endl;
            if(idx<=0) break;

            if(idx>i)
            result+=idx-i;

            // cout<<idx-i<<endl;

        }

        return result;

        
    }
};
