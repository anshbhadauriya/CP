/*

dfs hii hogaa

jis bhi ele ka left right na ho aur target ho delte that shi
 */
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return NULL;
        root->left=removeLeafNodes(root->left,target);
        root->right=removeLeafNodes(root->right,target);

        if(!root->left and !root->right and root->val==target){
            return NULL;
        }
        return root;
    }
};

/*
TC -> O(n)
SC-> O(n)
*/
