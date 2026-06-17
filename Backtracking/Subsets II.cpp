class Solution {
public:
vector<vector<int>>result;

void solve(int idx,vector<int>&curr,vector<int>&nums){

    
        result.push_back(curr);
    

    for(int i=idx;i<nums.size();i++){

    if(i>idx and nums[i]==nums[i-1]) continue;

    curr.push_back(nums[i]);
    solve(i+1,curr,nums);
    curr.pop_back();

    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        vector<int>curr;
        
        solve(0,curr,nums);

        return result;

        /*
        total 2 pow n subsets possible hai so 
        har subset ko ham jab result me dalte hai so uss subset ko copy krke dalna pdta hai result me
        so copy take O(n) time
        and we do sort initially

        TC- O(n)*O(2 pow n)+ O(nlogn)
             which is O(n 2 pow n)

        SC- total 2 pow n subsets will be inserted and O(n) for call stack (Recursion)
           which is O(n.2 pow n)
        */
        
    }
};
    
    Brute force->
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
