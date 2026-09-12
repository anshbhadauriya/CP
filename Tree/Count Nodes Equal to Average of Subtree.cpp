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

int answer=0;
pair<int,int> nodeCount(TreeNode* root){

    if(!root) return {0,0};

    auto left=nodeCount(root->left);
    auto right=nodeCount(root->right);

    int leftCount=left.first;
    int rightCount=right.first;

    int leftSum=left.second;
    int rightSum=right.second;

    if((leftSum+rightSum+root->val)/(leftCount+rightCount+1)==root->val) answer++;
    
    return {1+leftCount+rightCount, root->val+leftSum+rightSum};
}

    int averageOfSubtree(TreeNode* root) {
        nodeCount(root);

        return answer;
        
    }
};
