BFS->

/*
BFS is pretty simple

BFS done!

now lesstry dfs
 */
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {

        queue<TreeNode*>q;

        q.push(root);

        int sum=0;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();

            if(curr->val%2==0){ //mtlb even hai too

            //abh grand child check kro

            if(curr->left){
               

            if(curr->left->left)
             sum+=curr->left->left->val;

             if(curr->left->right)
             sum+=curr->left->right->val;
            }

            if(curr->right){ 

            if(curr->right->left)
             sum+=curr->right->left->val;

             if(curr->right->right)
             sum+=curr->right->right->val;
            }
            }

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);

            
        }

        return sum;
        
    }
};

/*
TC-> O(n)
SC-> O(w)
*/


DFS->

/*
BFS is pretty simple

BFS done!

now lesstry dfs

DFS DONE!!
 */
class Solution {
public:

int total=0;

int check(TreeNode* curr){
int sum=0;
    if(curr->left){
               

            if(curr->left->left)
             sum+=curr->left->left->val;

             if(curr->left->right)
             sum+=curr->left->right->val;
            }

            if(curr->right){ 

            if(curr->right->left)
             sum+=curr->right->left->val;

             if(curr->right->right)
             sum+=curr->right->right->val;
            }

            return sum;

}

    int sumEvenGrandparent(TreeNode* root) {

        if(!root) return 0;

        if(root->val%2==0){
        int temp=check(root);

        if(temp){
            // cout<<"root val is "<<root->val<<" and its sum is "<<temp<<endl;
            total+=temp;
        }
        }

        sumEvenGrandparent(root->left);
        sumEvenGrandparent(root->right);

        return total;


        
    }
};

/*
TC-> O(n)
SC-> O(h)
*/
