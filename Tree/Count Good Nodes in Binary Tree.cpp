BFS->
class Solution {
public:
/*

go in depth and keep a track of max value of path

if curr node val > max value of path -> count++

u can do this with bfs as well

*/

    int goodNodes(TreeNode* root) {

        queue<pair<TreeNode*,int>>q; //{node,maximum}

        q.push({root,INT_MIN});

        int count=0;

        while(!q.empty()){
            TreeNode* node=q.front().first;
            int maximum=q.front().second;
            q.pop();

            if(node->val>=maximum){
            count++;
            maximum=node->val;
            }

            if(node->left){
                q.push({node->left,maximum});
            }

            if(node->right){
                q.push({node->right,maximum});
            }

        }

        return count;
        
    }
};

DFS->

class Solution {
public:
/*

go in depth and keep a track of max value of path

if curr node val > max value of path -> count++

u can do this with bfs as well

bfs done now try dfs


*/
int count=0;

void solve(TreeNode* root,int maximum){

    if(!root) return;

    if(root->val>=maximum) count++;

    solve(root->left,max(maximum,root->val));
    solve(root->right,max(maximum,root->val));
}

    int goodNodes(TreeNode* root) {

    solve(root,INT_MIN);
    return count;
        
        /*TC and SC is O(n)*/
    }
};
