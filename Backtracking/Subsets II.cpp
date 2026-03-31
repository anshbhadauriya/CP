class Solution {
public:
void subsets(vector<int>&nums,vector<int>&current,set<vector<int>>&st,int idx){
    if(idx==nums.size()){
        st.insert(current);
        return;
    }
    current.push_back(nums[idx]);
    subsets(nums,current,st,idx+1);
    current.pop_back();
    subsets(nums,current,st,idx+1);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int idx=0;
        set<vector<int>>st;
        vector<int>current;
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        subsets(nums,current,st,idx);
        for(auto x:st){
            result.push_back(x);
        }
        return result;
    }
};
