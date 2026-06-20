/*
Brute force is easy--> just do inorder traversal and do store in vector and check is vector sorted or not

optimized->

do inorder 
aur kabhi bhi root<=prev return false


*/

class Solution {
public:

bool isValid=true;

long long prev=LLONG_MIN;

void inorder(TreeNode* root){

    if(!root or !isValid) return;

    inorder(root->left);

    if(root->val<=prev){
        isValid=false;
        return;
    }

    prev=root->val;

    inorder(root->right);
}
    bool isValidBST(TreeNode* root) {
        
         inorder(root);

         return isValid;
        
        
    }
};
/*
TC O(n)
SC O(h)
*/
