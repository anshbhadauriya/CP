class Solution {
public:

bool isSame(TreeNode* root,TreeNode* subRoot){
    if(!root and !subRoot) return true;
    if(root and !subRoot) return false;
    if(!root and subRoot) return false;
    if(root->val!=subRoot->val) return false;

    return isSame(root->left,subRoot->left) and isSame(root->right,subRoot->right);
}

bool traverse(TreeNode* root,TreeNode* subRoot){

    if(!root) return false;
    if(root->val==subRoot->val){
        if(isSame(root,subRoot)) return true;
    }
    if(traverse(root->left,subRoot)
    or traverse(root->right,subRoot)) return true;

    return false;
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        return traverse(root,subRoot);
        
    }
};

/*
TC O(n*m)

Space Complexity = O(H1 + H2)

Worst case (both skewed):
H1 = N
H2 = M
O(N + M)
Balanced trees:
H1 = log N
H2 = log M
O(log N + log M)
*/
