class Solution {
    #define ll long long
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        

        //track subarray distinct ele (unique) and freq of these distinct ele

       //if freq of these distinct ele == m so, valid++;

       //if unique==k an valid==k, try to shrink from left:-

       //if left ele freq is >m then only you can remove so number of times you can remove is the number of possible subarrays , ans++

       //if unique > k so, still you have to shrink from left to decrease unique :-

       //but what if left ele was contibuting to valid! so if it was contributing to valid so valid-- then remove that
       // if left ele freq is 0 then finally unique is decreased, so unique--
// we maintain extra , which is number of elements we can remove from current window still we will get valid window 

        unordered_map<int,int> hash;
        int l=0,unique=0,valid=0;
        int n=nums.size();
        ll ans=0;
        int extra=0;

        for(int r=0;r<n;r++){
            if(hash[nums[r]]==0) unique++;
            hash[nums[r]]++;
            if(hash[nums[r]]==m) valid++;
            while(unique>k){
                if(hash[nums[l]]==m) valid--;
                hash[nums[l]]--;
                if(hash[nums[l]]==0) unique--;
                l++;
                extra=0;
            }
            if(unique==k && valid==k){
                while(hash[nums[l]]>m){
                    hash[nums[l]]--;
                    l++;
                    extra++;    //itne elements ham log remove krde fir bhi window valid rhe
                }
                ans+=extra+1;
            }
        }
        return ans;
    }

};
