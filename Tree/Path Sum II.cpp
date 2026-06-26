/*
definetly a backtracking question

push back krte rho 

if sum > target return 

if sum==target push in result

this is without backtracking.. basically i generated all root to leaf paths and checked
but its not optimal obviously

so i have to backtrack somehow by using same vector

very happy that i done it by my own
 */
class Solution {
public:
vector<vector<int>>ans;

void dfs(TreeNode* root,int &targetSum,int &currSum,vector<int>&temp){
    if(!root) return;
    
    temp.push_back(root->val);
    currSum+=root->val;
    
    if(currSum==targetSum and !root->left and !root->right){
        ans.push_back(temp);
        currSum-=temp.back();
        temp.pop_back();
        return;
    }
    
 
    

    dfs(root->left,targetSum,currSum,temp);
    dfs(root->right,targetSum,currSum,temp);
    // cout<<temp.back()<<" ";
    currSum-=temp.back();
    temp.pop_back();
    


}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<int>temp;

        int currSum=0;

        
        dfs(root,targetSum,currSum,temp);

        return ans;
    }
};

/*
TC: O(N + K*H)
    N = number of nodes
    K = number of valid paths
    H = height of tree

    hame sare valid path ko push krna answer me so uss path ki copy banana kr push krne ki
    tc will be size of valid path H

SC: O(H) (excluding output)
    O(H + K*H) including output
*/

Pure recursive walaa->

  vector<vector<int>>ans;

void dfs(TreeNode* root,int &targetSum,int currSum,vector<int>temp){
    if(!root) return;
    
    temp.push_back(root->val);
    currSum+=root->val;
    
    if(currSum==targetSum and !root->left and !root->right){
        ans.push_back(temp);
        return;
    }
    
    // if(currSum>targetSum) return;
    

    dfs(root->left,targetSum,currSum,temp);
    dfs(root->right,targetSum,currSum,temp);
    // currSum-=temp.back();
    // temp.pop_back();

}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<int>temp;

        
        dfs(root,targetSum,0,temp);

        return ans;
    }
