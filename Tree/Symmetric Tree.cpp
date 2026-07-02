/* Time: O(n)
Space: O(h) (worst case O(n), balanced tree O(log n))
*/

class Solution {
public:

bool isSame(TreeNode* left_subtree,TreeNode* right_subtree){

   if(!left_subtree and !right_subtree) return true;

    
    if(!left_subtree and right_subtree) return false;

    if(left_subtree and !right_subtree) return false;

    if(left_subtree->val!=right_subtree->val) return false;

    if(isSame(left_subtree->left,right_subtree->right) and isSame(left_subtree->right,right_subtree->left)) return true;

    else return false;

}

    bool isSymmetric(TreeNode* root) {

        return isSame(root->left,root->right);
        

        
    }
};

BFS-> 

   /*
Now do this with level order traversal
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        queue<TreeNode*>q;

        q.push(root);


        while(!q.empty()){

            int n=q.size();

            vector<int>temp;

            for(int i=0;i<n;i++){

                TreeNode* curr=q.front();
                q.pop();

                if(curr->left){
                    q.push(curr->left);
                    temp.push_back(curr->left->val);
                } 
                else temp.push_back(-101);  //-101 indicates NULL

                if(curr->right){
                    q.push(curr->right);
                    temp.push_back(curr->right->val);
                }
                else temp.push_back(-101);

            }

            int l=0,h=temp.size()-1;
        //     cout<<"level is "<<level<<"-> ";
        //     for(auto x:temp) cout<<x<<" ";
        //     cout<<endl;


            while(l<h){
                if(temp[l]!=temp[h]) return false;
                l++;
                h--;
            }


        }

        return true;
        
    }
};
