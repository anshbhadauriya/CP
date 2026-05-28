class Solution {
public:
int solve(vector<int>&nums,int k){
    int l=0,h=0;
    int sum=0,result=0;
    unordered_map<int,int>mp;
    while(h<nums.size()){
        mp[nums[h]]++;
        while(mp.size()>k and l<=h){
            mp[nums[l]]--;
            if(mp[nums[l]]==0) mp.erase(nums[l]);
            l++;
        }
        result=result+(h-l+1);
        h++;
    }
    return result;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int a=solve(nums,k);
        int b=solve(nums,k-1);
        return a-b;
        
    }
};
