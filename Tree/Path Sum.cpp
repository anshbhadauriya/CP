/*
do same as path sum 2 here just return true or false
 */
class Solution {
public:
bool dfs(TreeNode* root,int targetSum,int currSum){

    if(!root) return false;

    if(!root->left and !root->right and currSum+root->val==targetSum) return true;

    if(dfs(root->left,targetSum,currSum+root->val) or
    dfs(root->right,targetSum,currSum+root->val))
     return true;

     return false;
    
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        int currSum=0;
        return dfs(root,targetSum,currSum);        
    }
};

/*
TC-> O(n)
SC-> O(h)
*/
