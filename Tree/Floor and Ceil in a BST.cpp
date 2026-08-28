class Solution{	
	public:
		vector<int> floorCeilOfBST(TreeNode* root,int key){

            int ceil=-1,floor=-1;

            while(root){

                if(root->val==key){

                    ceil=root->val;
                    floor=root->val;
                    break;
                }
                else if(root->val>key){
                    ceil=root->val;
                    root=root->left;
                }
                else{
                    floor=root->val;
                    root=root->right;
                }
            }

            return {floor,ceil};
		}
};
