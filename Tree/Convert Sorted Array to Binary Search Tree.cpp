/*
See the GIF in the discussion section for visualization.

Recursion thinking:

Don't try to simulate the entire recursion tree.

Just think about the current range [l...h].

1. Which element should become the root?
   -> The middle element.

2. How do I build the left subtree?
   -> Same problem on [l...mid-1].

3. How do I build the right subtree?
   -> Same problem on [mid+1...h].

The recursive function returns:
Root of the balanced BST formed from nums[l...h]

Therefore after creating the current root and attaching
the left and right subtrees, we simply return curr
*/
class Solution {
public:

TreeNode* solve(int l,int h,vector<int>&nums){

    if(l>h) return NULL;

    int mid=l+(h-l)/2;

    TreeNode* curr= new TreeNode(nums[mid]);

     curr->left=solve(l,mid-1,nums);

     curr->right=solve(mid+1,h,nums);

     return curr;

}
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return solve(0,nums.size()-1,nums);
        
        /*
        TC O(n)
        SC = O(log n)   // because the tree is balanced
        */
    }
};
