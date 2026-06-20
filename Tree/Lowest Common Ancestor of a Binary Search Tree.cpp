class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        while(root){

        if(p->val > root->val and q->val > root->val) 
         root=root->right;

        else if(p->val < root->val and q->val < root->val)
         root=root->left;
    
        else return root;  //jab root p and q me ek se bada hoga ek se chota so it means p left me hai q right me yaa fir q left me hai p right me
        }
        return NULL;
        
    }
};
/*
TC O(h)
SC O(1)
*/
