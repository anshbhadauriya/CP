For OA's->

  class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        sort(nums.begin(), nums.end());   // IMPORTANT
        vector<vector<int>> ans;

        do {
            ans.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));

        return ans;
    }
};


For interviews->

class Solution {
public:
void solve(vector<int>&nums,vector<int>&curr,vector<vector<int>>&answer,vector<int>&freq){
    if(curr.size()==nums.size()){
        answer.push_back(curr);
        return;
    }

    for(int i=0;i<nums.size();i++){
        if(!freq[i]){   //agr element visited nhi hai mtlb vo curr me nhi hai to usse curr me dalo, visited kro , then again call recursion to do same thing now after recursion call is done we have to go back in previous state so make it unvisited and remove last inserted element to make it like previous state (backtracking)
            curr.push_back(nums[i]);
            freq[i]=1;
            solve(nums,curr,answer,freq);
            freq[i]=0;
            curr.pop_back();

        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>>answer;

        vector<int>freq(nums.size(),0);  //check krne ke lie ki number visited hai ya nhi,  we can use hashmap or set but constraints size is less so we should use vector for optimality of space

        solve(nums,curr,answer,freq);
        return answer;
    }
};
