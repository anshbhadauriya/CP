class Solution {
public:
void solve(TreeNode* root,vector<int>&ans){
    if(!root) return;
    solve(root->left,ans);

    ans.push_back(root->val);

    solve(root->right,ans);
}
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        solve(root,ans);
        return ans[k-1];

    }
};
/*(
TC-> O(n)
SC-> O(h)+O(n)==O(h)
*/
