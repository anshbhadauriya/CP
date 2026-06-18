/* Time: O(n)
Space: O(h) (worst case O(n), balanced tree O(log n))
*/

class Solution {
public:

bool isSame(TreeNode* left_subtree,TreeNode* right_subtree){

   if(!left_subtree and !right_subtree) return true;

    
    if(!left_subtree and right_subtree) return false;

    if(left_subtree and !right_subtree) return false;

    if(left_subtree->val!=right_subtree->val) return false;

    if(isSame(left_subtree->left,right_subtree->right) and isSame(left_subtree->right,right_subtree->left)) return true;

    else return false;

}

    bool isSymmetric(TreeNode* root) {

        return isSame(root->left,root->right);
        

        
    }
};
