class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        set<vector<int>>st;
        for(int i=0;i<nums.size()-2;i++){

            int l=i+1,h=nums.size()-1;
            while(l<h){
                int sum=nums[i]+nums[l]+nums[h];
                if(sum==0){
                    st.insert({nums[i],nums[l],nums[h]});
                    l++;
                    h--;
                }
                if(sum>0){
                    h--;
                }
                else if(sum<0){
                    l++;
                }
            }
        }
        vector<vector<int>>answer;
        for(auto x:st){
            answer.push_back(x);
        }
        return answer;
    }
};