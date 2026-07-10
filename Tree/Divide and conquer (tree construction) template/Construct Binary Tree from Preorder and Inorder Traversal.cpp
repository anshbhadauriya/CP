/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* solve(int l,int h,vector<int>&inorder,vector<int>&preorder,int pre_st,int pre_end,unordered_map<int,int>&mp){

    if(l>h) return NULL;

    if(pre_st>pre_end) return NULL;

    int root_node=preorder[pre_st];

    int mid=mp[root_node];

    TreeNode* dummy= new TreeNode(root_node);

    int left_subtree_size=(mid-1)-l+1;
    int right_subtree_size=h-(mid+1)+1;
    int pre_l1=pre_st+1;
    int pre_h1=pre_st+left_subtree_size;
    int pre_l2=pre_st+left_subtree_size+1;
    int pre_h2=pre_end;

    dummy->left=solve(l,mid-1,inorder,preorder,pre_l1,pre_h1,mp);
    dummy->right=solve(mid+1,h,inorder,preorder,pre_l2,pre_h2,mp);
    
    return dummy;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int,int>mp;

        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }

       return solve(0,preorder.size()-1,inorder,preorder,0,preorder.size()-1,mp);
        
    }
};
