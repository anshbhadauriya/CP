/*
if u take parent u can not take its children
har point pr we have 2 options
take and go to grand child
skip
 */
class Solution {
public:
unordered_map<TreeNode*,unordered_map<int,int>>dp;
int dfs(TreeNode* root,bool taken){

    if(!root) return 0;

    if(dp[root].count(taken)) return dp[root][taken];

    int take=0,skip=0;
    if(!taken)
     take=root->val+dfs(root->left,true)+dfs(root->right,true);

     skip=dfs(root->left,false)+dfs(root->right,false);

    return dp[root][taken]=max(take,skip);
}
    int rob(TreeNode* root) {

        
        return dfs(root,false);
        
    }
};
