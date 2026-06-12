class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        queue<TreeNode*>q;

        q.push(root);

        vector<vector<int>>result;

        if(!root) return result;

        while(!q.empty()){

            int n=q.size();

            vector<int>temp;

            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();

                temp.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            result.push_back(temp);
        }

        return result;
        
    }
};
