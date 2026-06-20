/* 
Idea:

BST diya hua hai aur uska preorder traversal diya hua hai.

Observation:

- BST ka inorder traversal hamesha sorted hota hai.
- Isliye preorder ko sort kar denge to inorder mil jayega.

Ab problem convert ho gayi:

"Construct Binary Tree from Preorder + Inorder"

Rules:

1. Preorder ka first element hamesha root hota hai.
2. Root ko inorder me search karo.
3. Root ke left wale elements left subtree me honge.
4. Root ke right wale elements right subtree me honge.
5. Inorder se left subtree ka size nikal lenge.
6. Us size ki help se preorder ko left aur right subtree ke parts me divide kar denge.

Example:

Preorder = [8,5,1,7,10,12]
Inorder  = [1,5,7,8,10,12]

Root = 8

Inorder:
[1,5,7] 8 [10,12]

Left subtree size = 3

To preorder me:

8 | 5 1 7 | 10 12
    left     right

Ab recursively same kaam left aur right subtree ke liye karenge.

TC:
Sorting -> O(n log n)
Tree Construction -> O(n)

Overall -> O(n log n)

SC:
O(n) hashmap + recursion stack
*/

class Solution {
public:
TreeNode* solve(int l,int h,vector<int>&inorder,vector<int>&preorder,int pre_st,int pre_end,unordered_map<int,int>&mp){

    // subtree me koi node nahi bachi
    if(l>h) return NULL;
    if(pre_st > pre_end) return NULL;

     // current preorder range ka first element root hoga
    int root_node=preorder[pre_st];

     // inorder me root ki position
    int mid=mp[root_node];

    TreeNode* curr=new TreeNode(root_node);

    

    int left_subtree_size=(mid-1)-l+1;
    int right_subtree_size=h-(mid+1)+1;
    int pre_l1=pre_st+1;
    int pre_h1=pre_st+left_subtree_size;
    int pre_l2=pre_st+left_subtree_size+1;
    int pre_h2=pre_end;

    curr->left=solve(l,mid-1,inorder,preorder,pre_l1,pre_h1,mp);
    curr->right=solve(mid+1,h,inorder,preorder,pre_l2,pre_h2,mp);

    return curr;
}

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder(preorder.begin(),preorder.end());

        unordered_map<int,int>mp;

        sort(inorder.begin(),inorder.end());

        for(int i=0;i<preorder.size();i++){
            mp[inorder[i]]=i;
        }

        return solve(0,preorder.size()-1,inorder,preorder,0,preorder.size()-1,mp);
        
    }
};
