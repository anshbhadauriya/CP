class Solution {
public:
unordered_set<int>st;
bool solve(TreeNode* root,int k){

    if(!root) return false;

    if(st.count(k-root->val)) return true;

    st.insert(root->val);

    return solve(root->left,k) or solve(root->right,k);
    
}
    bool findTarget(TreeNode* root, int k) {
        return solve(root,k);
    }
};
/*
TC-> O(n)
Sc->O(h)
*/
