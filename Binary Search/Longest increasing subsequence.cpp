class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;

        for(int i=0;i<nums.size();i++){
            int curr=nums[i];
            if(temp.empty() or curr>temp.back()){
                temp.push_back(nums[i]);
                continue;
            }

            int l=0,h=temp.size()-1;
            
            int ans=h;
            while(l<=h){
                int mid=l+(h-l)/2;
                if(temp[mid]>=curr){
                    ans=mid;
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            temp[ans]=curr;

        }
        return temp.size();
    }
};
