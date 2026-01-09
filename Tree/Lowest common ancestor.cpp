class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;

        if(root->val==p->val or root->val==q->val) return root;  //sare node check kro ki kisi me bhi p or q me se koi hai agar hai too ussi recurisve call me vo node return kro

        TreeNode* left=lowestCommonAncestor(root->left,p,q);  //har node ke left me check
        TreeNode* right=lowestCommonAncestor(root->right,p,q);  //har node ke right me check

        if(left!=NULL and right!=NULL) return root;  //agr left aur right dono me NULL nhi hai mtlb dono p and q hai so return this nide

        if(left!=NULL and right==NULL) return left;  //agr left me p or q hai but right me NULL so return that left (see testcase 2)

        if(right!=NULL and left==NULL) return right;  //same for right 

        return NULL;  //left aur right dono null hai
    }
};
