class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int minimum=INT_MAX;
        int l=1,h=*max_element(nums.begin(),nums.end());
        while(l<=h){
            int mid=l+(h-l)/2;
            int sum=0;
            for(int i=0;i<nums.size();i++){
                sum=sum+ceil((double)nums[i]/mid);
            }

            if(sum>threshold){ 
                l=mid+1;
                
            }
            else{
                minimum=min(minimum,mid);
                h=mid-1;
            }

        }
        return minimum;
    }
};
