Q1->

  class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maximum=*max_element(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size();i++){
            count=count+abs(nums[i]-maximum);
        }
        return count;
    }
};

Q2->

  class Solution {
public:

    int countMajoritySubarrays(vector<int>& nums, int target) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int freq=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]==target){
                    freq++;
                }

            if(freq>(j-i+1)/2){
                count++;
            }
                
            }
        }
        return count;
    }
};
