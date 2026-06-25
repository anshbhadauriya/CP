/*
Easy

har root ke lie

left wale ko right me krdo 
right wale ko left me krdo
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if(!root) return NULL;

        root->left=invertTree(root->left);
        root->right=invertTree(root->right);

            TreeNode* tempL=NULL;
            TreeNode* tempR=NULL;

            if(root->left) tempL=root->left;
            if(root->right) tempR=root->right;

            root->left=tempR;
            root->right=tempL;

            return root;

        
        
    }
};

/*
TC-> O(n)
SC-> O(h)
*/
