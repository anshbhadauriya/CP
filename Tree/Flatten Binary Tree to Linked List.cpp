/*

Dekho basic idea yeh hai ki

       curr
     /    \
   Left   Right
 
     isko convert krna hai isme:-

        curr
         \
          Left
            \
             Right

    so left subtree ke right most agr curr ke right me jodna hai soo its obv ki hame morris traversal use krna pdega

Find the rightmost node of the left subtree
Connect its right to the current node's original right subtree
Move left subtree to the right
Set left = NULL
Move to current->right
    


 */
class Solution {
public:

    void flatten(TreeNode* root) {

        if(!root) return;
        

        TreeNode* curr=root;

        while(curr){

            if(curr->left){

                TreeNode* leftChild=curr->left;

                while(leftChild->right) leftChild=leftChild->right;

                leftChild->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }

            curr=curr->right;
        }

        
    }
};

/*
TC is O(n)
Sc is O(1)
*/
