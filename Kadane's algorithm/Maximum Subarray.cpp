class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev=nums[0];
        int maximum=nums[0];

        for(int i=1;i<nums.size();i++) {
            prev=max(nums[i],prev+nums[i]); 
            maximum=max(maximum,prev);
        }

        return maximum;
    }
};
