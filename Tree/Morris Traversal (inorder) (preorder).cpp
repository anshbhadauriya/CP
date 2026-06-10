/*

Morris traversal: (inorder)

goal is : hame vaps aane ka path pehle hi set kr dena hai so we dont have to use recusive calls

root ke left ke rightmost child ko root se connect kro


do dry run for better understanding
isse vaps jane ka path mil jaega so you dont have to do recusrive call so SC will be O(1)

there are 2 versions 
codestorymik seems easy but usme tree ko hi modify kr dia hai 
so better is to watch striver's version for revision (watch his dryrun automatic smjh aajaega) aaur usse preorder bhi ek line ke diff me hojaega
watch at 10:20 

TC O(n)
SC O(1)


to convert this in pre order traversal there is just one line difference

else if se result.push_back() wali condition ko if me daldo 


 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

       vector<int>result;

       TreeNode* curr=root;

       while(curr!=NULL){

        if(curr->left==NULL){  //leaf node pr aagae of left side
            result.push_back(curr->val);
            curr=curr->right;
        }

        else{
            //left ke rightmost node ko curr se connect kro too vaps aane ka path bnega
            TreeNode* leftChild=curr->left;

            while(leftChild->right!=NULL and leftChild->right!=curr){
                leftChild=leftChild->right;
            }

            //agr null hai too connect krdo curr se

            if(leftChild->right==NULL){
                leftChild->right=curr;
                curr=curr->left;
            }

            //yeh case tab hoga jab ham pehle hi traverse kr chuke hai pura left subtree aur vo already connected hai curr se...(watch strivers vide at 11:10) 
            else if(leftChild->right==curr){

                result.push_back(curr->val);
                leftChild->right=NULL;
                curr=curr->right;
            }

        }

       }

       return result;
        
    }
};
