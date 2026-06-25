BFS->
class Solution {
public:
/*
Try BFS first

agr curr level even ho so just curr->left or right ko swap krdo


BFS Done!

Now try dfs

*/
void dfs(TreeNode* leftChild,TreeNode* rightChild,int level){

    if(!leftChild or !rightChild) return;
    if(level%2==0){

        swap(leftChild->val,rightChild->val);

    }

    dfs(leftChild->left,rightChild->right,level+1);
    dfs(leftChild->right,rightChild->left,level+1);
}
    TreeNode* reverseOddLevels(TreeNode* root) {

        dfs(root->left,root->right,0);

        return root;

        
    }
};

/*
TC-> O(n)
SC->O(h)
*/


DFS->

  
  
  class Solution {
public:
/*
Try BFS first

agr curr level even ho so just curr->left or right ko swap krdo


BFS Done!

Now try dfs

*/
void dfs(TreeNode* leftChild,TreeNode* rightChild,int level){

    if(!leftChild or !rightChild) return;
    if(level%2==0){

        swap(leftChild->val,rightChild->val);

    }

    dfs(leftChild->left,rightChild->right,level+1);
    dfs(leftChild->right,rightChild->left,level+1);
}
    TreeNode* reverseOddLevels(TreeNode* root) {

        dfs(root->left,root->right,0);

        return root;

        
    }
};

/*
TC-> O(n)
SC->O(h)
*/
