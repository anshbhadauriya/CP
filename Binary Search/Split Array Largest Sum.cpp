class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int h=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            bool flag=false;
            int temp_sum=0;
            int count=1;
            for(int i=0;i<nums.size();i++){
                if(nums[i]>mid){
                    flag=true;
                    break;
                }
                if(temp_sum+nums[i]<=mid){
                temp_sum=temp_sum+nums[i];
                }
                else{
                    count++;
                    temp_sum=0;
                    i--;
                }
            }
            if(!flag and count<=k){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;

            }
        }
        return ans;
    }
};
