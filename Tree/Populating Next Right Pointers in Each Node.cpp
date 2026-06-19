/*
Tricky observation is 

root->right->next=root->next->left

copy me yeh condition apply kro smjh jaoge!
*/

class Solution {
public:
void solve(Node* root){

    if(!root) return;

    if(root->left and root->right){
        root->left->next=root->right;
    }

    if(root->right and root->next){
        root->right->next=root->next->left;
    }


    solve(root->left);
    solve(root->right);
}
    Node* connect(Node* root) {
        if(!root) return NULL;
        Node* save=root;
        solve(root);

        return save;

        /*
        TC ->O(n)

        Since recursion depth equals tree height:

        Perfect binary tree height = log n
        
        Recursion stack = O(log n)

        SC-> O(log n)
        */
    }
};
