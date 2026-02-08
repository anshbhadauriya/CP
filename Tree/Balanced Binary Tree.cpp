/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int height(TreeNode* root){   //idhr se given tree ki height pta kro
    if(!root) return 0;
    int left_h=height(root->left);
    int right_h=height(root->right);
    return max(left_h,right_h)+1;
}

    bool isBalanced(TreeNode* root) {  //idhr se sare subtree height function me bhejo 
        if(!root) return true;

        int left_height=height(root->left);  
        int right_height=height(root->right);

        if(abs(left_height-right_height)>1) return false;

        return isBalanced(root->left) and isBalanced(root->right);  

    }
};
