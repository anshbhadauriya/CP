class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pref=1,suff=1,n=nums.size(),maximum=nums.front();
        for(int i=0;i<n;i++){
            if(pref==0) pref=1;
            if(suff==0) suff=1;
            pref=pref*nums[i];
            suff=suff*nums[n-i-1];
            maximum=max({maximum,pref,suff});
        }
        return maximum;
    }
};
