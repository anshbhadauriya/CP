class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        /*
        
        can we use same appraoch as 3sum here?
        lets try

        worked! 

        now do without set for space optimization

        final TC after optimization 

        O(n log n) + O(n * n * n)
        = O(n^3)

        SC O(1)


        */

        sort(nums.begin(),nums.end());

        vector<vector<int>>result;

        int n=nums.size();

        for(int i=0;i<n-3;i++){

            if(i>0 and nums[i]==nums[i-1]) continue;

            for(int j=i+1;j<n-2;j++){

                if(j>i+1 and nums[j]==nums[j-1]) continue;  //j>i+1 isslie kyuki j ki range hi i+1 hai so think i+1 as a first idx and i+2 second idx for j 

                int l=j+1,h=n-1;

                while(l<h){

                long long sum=(1LL*nums[i]+1LL*nums[j]+1LL*nums[l]+1LL*nums[h]);

                if(sum==target){
                    result.push_back({nums[i],nums[j],nums[l],nums[h]});
                    l++;
                    h--;

                    while(l<h and nums[l]==nums[l-1]) l++;

                    while(l<h and nums[h]==nums[h+1]) h--;
                }
                else if(sum>target) h--;

                else l++;
            }
            }
        }

        return result;
        
    }
};
