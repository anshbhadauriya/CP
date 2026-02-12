class Solution {
public:
void solve(int number,int sum,vector<int>&curr,vector<vector<int>>&answer,int limit,int target){

    if(curr.size()>limit) return;

    if(sum>target) return;  //ok
    
     if(sum==target and curr.size()==limit){
        answer.push_back(curr);
        return;
    }

    if(number>9) return;

   

    curr.push_back(number);

    solve(number+1,sum+number,curr,answer,limit,target); //take kro

    curr.pop_back();

    solve(number+1,sum,curr,answer,limit,target); //skip kro
}
    vector<vector<int>> combinationSum3(int limit, int target) {
        vector<int>curr;

        vector<vector<int>>answer;

        solve(1,0,curr,answer,limit,target);     
        return answer; 
    }
};
