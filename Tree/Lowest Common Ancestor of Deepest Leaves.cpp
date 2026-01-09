class Solution {
public:
unordered_map<int,int>mp;
int max_depth=0;

TreeNode* LCA(TreeNode* root){
    if(root==NULL or mp[root->val]==max_depth){
        return root;
    }

    TreeNode* left=LCA(root->left);
    TreeNode* right=LCA(root->right);

    if(left!=NULL and right!=NULL) return root;

    if(left!=NULL) return left;
     
     return right;
}

void depth(TreeNode* root,int d){

    if(!root) return;

    max_depth=max(max_depth,d);
    mp[root->val]=d;
    depth(root->left,d+1);
    depth(root->right,d+1);

}

    TreeNode* lcaDeepestLeaves(TreeNode* root) {

        depth(root,0);


        return LCA(root);
        
    }
};
