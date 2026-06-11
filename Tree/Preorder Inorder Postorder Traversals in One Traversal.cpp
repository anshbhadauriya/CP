class Solution {
public:
    vector<vector<int>> allTraversal(TreeNode* root) {

        vector<int> pre, in, post;

        if(root == NULL) return {pre, in, post};

        stack<pair<TreeNode*, int>> st;

        st.push({root, 1});

        while(!st.empty()) {

            TreeNode* node = st.top().first;
            int state = st.top().second;
            st.pop();

            if(state == 1) {

                pre.push_back(node->val);

                st.push({node, 2});

                if(node->left)
                    st.push({node->left, 1});
            }
            else if(state == 2) {

                in.push_back(node->val);

                st.push({node, 3});

                if(node->right)
                    st.push({node->right, 1});
            }
            else {

                post.push_back(node->val);
            }
        }

        return {pre, in, post};
    }
};
