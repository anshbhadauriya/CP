class Solution {
public:

/*
use same pattern as subset 2
*/
  vector<vector<int>>result;
void solve(int idx,int sum,vector<int>&curr,vector<int>&candidates,int target){

    if(sum==target){
    result.push_back(curr);
    return; 
    }

    if(sum>target) return;

    if(idx>=candidates.size()) return;

    for(int i=idx;i<candidates.size();i++){

        if(i>idx and candidates[i]==candidates[i-1]) continue;
        curr.push_back(candidates[i]);
        solve(i+1,sum+candidates[i],curr,candidates,target);
        curr.pop_back();

    }

  

}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(),candidates.end());

        vector<int>curr;

        int sum=0;

        solve(0,sum,curr,candidates,target);

    

        return result;

        /*
        tc-> O(2^n)
        sc-> O(n)
        */
        
    }
};
