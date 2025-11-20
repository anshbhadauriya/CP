class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;

        for(int i=0;i<nums.size();i++){
            int curr=nums[i];
            if(temp.empty() or curr>temp.back()){
                temp.push_back(nums[i]);
                continue;
            }

            int idx=lower_bound(temp.begin(),temp.end(),curr)-temp.begin();
            temp[idx]=curr;
        }
        return temp.size();
    }
};
