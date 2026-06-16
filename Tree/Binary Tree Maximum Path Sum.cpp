/*
Ham har node pr jaege aur check krege left path se zyda sum milega ya right se
 */
class Solution {
public:
int ans=INT_MIN;
int dfs(TreeNode* root){
    if(!root) return 0;

    int curr=root->val;
    int left=max(0,dfs(root->left));
    int right=max(0,dfs(root->right));

    ans=max(ans,curr+left+right);

    return curr+max(left,right); //left path explore krne me zyda sum milega ya right
}
    int maxPathSum(TreeNode* root) {

        dfs(root);

        return ans;
        /*
        TC-> O(n)
        SC-> O(h)
        */
        
    }
};
