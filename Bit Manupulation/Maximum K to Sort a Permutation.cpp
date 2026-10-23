/*
u can only swap if nums[i] & nums[j] == k 
so jitne jo bhi ele apni position me na ho unka AND nikaldo
*/
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        
        // vector<int>temp(nums.begin(),nums.end());

        // sort(temp.begin(),temp.end());

        int ans=-1,n=nums.size();

        for(int i=0;i<n;i++){

            if(nums[i]!=i) ans=ans & nums[i]; 

        }

        return ans==-1?0:ans;
    }
};
