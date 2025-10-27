class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maximum=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                nums[i]=-1;
            }
        }
        mp[0]=-1;

        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            if(mp.find(sum)!=mp.end()){
                int idx=mp[sum];
                maximum=max(maximum,i-idx);
            }
            else{
                mp[sum]=i;
            }
        }
        return maximum;
    }
};