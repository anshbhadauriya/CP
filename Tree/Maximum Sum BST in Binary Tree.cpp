/*
koi node bst tabhi hoga jab 

curr > left subtree max and curr < right subtree min

so for each node u have to track max and min

but to find sum you also have to track sum

so do post order
 */
class Solution {
public:
int maximum=0;
vector<int> solve(TreeNode* root){

    if(!root){

        return {INT_MAX,INT_MIN,0}; //yeh condition hemsha valid hogi for BST
    }

    auto left=solve(root->left);
    auto right=solve(root->right);

    int left_subtree_min=left[0];
    int left_subtree_max=left[1];
    int left_subtree_sum=left[2];

    int right_subtree_min=right[0];
    int right_subtree_max=right[1];
    int right_subtree_sum=right[2];


    if(root->val > left_subtree_max and root->val < right_subtree_min){

        int curr_sum=left_subtree_sum+right_subtree_sum+root->val;

        maximum=max(maximum,curr_sum);

        int curr_min=min(root->val,left_subtree_min);
        int curr_max=max(root->val,right_subtree_max);

        return {curr_min,curr_max,curr_sum};
    }

    //agr bst nhi hai too retun this as invalid bcs yeh bhejne se bst aage continue nhi ho paega 
    return {INT_MIN,INT_MAX,0};



    
}
    int maxSumBST(TreeNode* root) {

        solve(root);

        return maximum;
        
    }
};

/*
TC-> O(n)
SC-> O(h)
*/
