class Solution {
public:
TreeNode* solve(int in_st,int in_end,int post_st,int post_end,vector<int>&inorder,vector<int>&postorder,unordered_map<int,int>&mp){

    if(in_st>in_end) return NULL;
    if(post_st>post_end) return NULL;

    int root_node=postorder[post_end];

    int mid=mp[root_node];

    TreeNode* dummy= new TreeNode(root_node);

    int left_subtree_size=(mid-1)-in_st+1;
    int right_subtree_size=in_end-(mid+1)+1;
    int l1=post_st;
    int h1=post_st+left_subtree_size-1;
    int l2=h1+1;
    int h2=l2+right_subtree_size-1;

    dummy->left=solve(in_st,mid-1,l1,h1,inorder,postorder,mp);
    dummy->right=solve(mid+1,in_end,l2,h2,inorder,postorder,mp);

    return dummy;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n=postorder.size();

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }

        return solve(0,n-1,0,n-1,inorder,postorder,mp);
        
    }
};
