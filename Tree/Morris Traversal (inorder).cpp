/*

Morris traversal: (inorder)

root ke left ke rightmost child ko root se connect kro
root to left ka path 

do dry run for better understanding
isse vaps jane ka path mil jaega so you dont have to do recusrive call so SC will be O(1)

TC O(n)
SC O(1)

 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int>result;

        TreeNode* curr=root;

        while(curr!=NULL){

            if(curr->left==NULL){
                result.push_back(curr->val);
                curr=curr->right;
            }

            else{
            TreeNode* LeftChild=curr->left;

            while(LeftChild->right!=NULL) LeftChild=LeftChild->right; //leftchild ke right most me aao

            LeftChild->right=curr;  //abh vps root se connect krdo

            //abh curr ko aage bhi badana hai aur curr ke left ko null bhi krna hai

            TreeNode* temp=curr;

            curr=curr->left;

            temp->left=NULL;

            }


        }


        return result;

        
    }
};
