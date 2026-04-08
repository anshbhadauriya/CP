class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int MOD=1e9+7;
        for(auto &x:queries){
            int l=x[0],r=x[1],k=x[2],v=x[3];
            int idx=l;

            while(idx<=r){
                nums[idx]=(1LL*nums[idx]*v)%MOD;
                idx+=k;
            }
            
            
        }
        for(auto x:nums) cout<<x<<" ";
        int xorr=nums.front();

        for(int i=1;i<nums.size();i++) xorr=xorr^nums[i];

        return xorr;
        
    }
};
