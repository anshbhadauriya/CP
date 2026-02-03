class Solution {
public:
int count=0;
void solve(int i,vector<int>&nums,int k,unordered_map<int,int>&mp){  
    if(i==nums.size()){
        count++;
        return;
    }
    solve(i+1,nums,k,mp);

    if(mp[nums[i]+k]==0 && mp[nums[i]-k]==0){
        mp[nums[i]]++;
        solve(i+1,nums,k,mp);
        mp[nums[i]]--;

       
    }
    
}
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        solve(0,nums,k,mp);
        return count-1;   //-1 isslie kyuki last me ek empty subset bachega {}   vo bhi count increase krdega j
    }
};
