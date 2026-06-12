/*

Basically ham har node pr jaege aur uske left subtree ke max depth nikalege aur right subtree 
too total diameter hojaegi=leftTree+rightTree

jis node ki bhi max hue return that

return max(diamater from curr node, diameter from left node , diameter from right node)
 */
class Solution {
public:
int depth(TreeNode* root){
    if(!root) return 0;

    return 1+max(depth(root->left),depth(root->right));
}

    int diameterOfBinaryTree(TreeNode* root) {

        if(!root) return 0;

        int left=depth(root->left);
        int right=depth(root->right);

        int currDiameter=left+right;

        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);

        return max(currDiameter, max(leftDiameter, rightDiameter));
    
        
    }
};
