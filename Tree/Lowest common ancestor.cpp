Simple version->

/*

root se lekr p tk path nikalo
root se lekr q tk path nikalo
jo bhi first uncommon ho vo return krdo
 */
class Solution {
public:
bool findPath(TreeNode* root,TreeNode* target,vector<TreeNode*>&path){

    if(!root) return false; //current path me target nhi mila mtlb so return false

    path.push_back(root);

    if(root==target) return true;  //agr target mil gya so we dont need to expore more

    if(findPath(root->left,target,path) or findPath(root->right,target,path)) return true;
    //path found return true

    path.pop_back(); //current path me null aagya mtlb target nhi mila so remove current path

    return false;

}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>p_path,q_path;

        findPath(root,p,p_path);
        findPath(root,q,q_path);

        int i=0;

        while(i<p_path.size() and i<q_path.size() and p_path[i]==q_path[i]){
            i++;
        }

        return p_path[i-1];

        /*
        TC-> O(n)
        Sc-> O(n)
        */

        
    }
};

Optimized->

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
