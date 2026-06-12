/*

Har node ka node idx number nikalo using 2*idx+1 and 2*idx+2

level order traversal krdo

queue ka first wala aur last wale ka difference nikalo 

jis level ka maximum diff ho return that
 
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,long long>>q;  //{root,idx}

        long long maximum=0;
        
        q.push({root,0});


        while(!q.empty()){
            
            int n=q.size();

            long long first=q.front().second;
            long long last=q.back().second;

            maximum=max(maximum,last-first+1);

            for(int i=0;i<n;i++){

                TreeNode* node=q.front().first;
                long long idx=q.front().second-first;   //first se isslie minus so we can prevent overflow at next step which is 2*i+2 so agr level ke pehle wale ele se minus kro too pehla ele 0 hojaega aur sbki val kam hojaegi
                q.pop();

                if(node->left) q.push({node->left,2*idx+1});
                if(node->right) q.push({node->right,2*idx+2});
            }
        }

        return maximum;
    }
};
