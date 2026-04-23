class Solution {
public:
using ll= long long;
    vector<long long> distance(vector<int>& nums) {

        /* 
        we need to find 2 things

        left side freq of curr ele and right side freq of curr ele

        sum of idx of left side and sum of idx of right side

        find freq of ele till now and then save that freq in prefix

        */

        ll n=nums.size();

        unordered_map<ll,ll>left_idx_sum,left_idx_count;

        vector<ll>left(n,0),right(n,0);

        vector<ll>res;

        for(ll i=0;i<nums.size();i++){
            ll curr=nums[i];

            ll sum=left_idx_sum[curr];
            ll freq=left_idx_count[curr];

            left[i]=(freq*i)-(sum);

            left_idx_sum[curr]+=i;
            left_idx_count[curr]++;
            
        }


        unordered_map<ll,ll>right_idx_sum,right_idx_count;

        

        for(ll i=n-1;i>=0;i--){
            ll curr=nums[i];

            ll sum=right_idx_sum[curr];
            ll freq=right_idx_count[curr];

            right[i]=(sum)-(freq*i);

            right_idx_sum[curr]+=i;
            right_idx_count[curr]++;

        }

        for(ll i=0;i<n;i++){
            
            ll curr_sum=left[i]+right[i];

            res.push_back(curr_sum);
        }
        

        return res;
        
    }
};
