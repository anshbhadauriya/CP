/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        /*
        parent  chid   left

        har parent ke andr uske child daldo

        20-> 15,17

        80-> 19

        50-> 20,80

        aissa konsa sa node hai jiski indegree 0 hai vhi node root hoga

        aur ek bar root mil gya too uske child left right dedo

        fir unke child ke left right nikalo and keep going

        but how can i find ele with indegree 0??

        */

        
        unordered_map<int,TreeNode*>mp;

        unordered_set<int>st;


        for(auto x:descriptions){

            int parent=x[0],child=x[1],isLeft=x[2];

            if(!mp.count(parent)){
                mp[parent]=new TreeNode(parent);
            }

            if(!mp.count(child)){
                mp[child]=new TreeNode(child);
            }

            if(isLeft)  mp[parent]->left=mp[child];

            else mp[parent]->right=mp[child];

            st.insert(child);
            
        }

        //abh bss parent return krdo

        for(auto x:descriptions){
            
            int parent=x[0];

            if(!st.count(parent)) return mp[parent];
        }

        return NULL;




        
    }
};
