/*
simple hai

column wise values group banana hai

agr kisi group me ek se zyda ele hai too 
sort by rows 
if row equal then sort wise col 

so sort krdo pehle {row,ele} wale vector ko

Time Complexity:  O(N log N)
Space Complexity: O(N)

*/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        queue<pair<TreeNode*,pair<int,int>>>q;  //{{node, {int,int}}

        map<int,vector<pair<int,int>>>mp;

        q.push({root,{0,0}});

        while(!q.empty()){

            TreeNode* node=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();

            mp[y].push_back({x,node->val});

            if(node->left){
                q.push({node->left,{x+1,y-1}});
            }
            if(node->right){
                q.push({node->right,{x+1,y+1}});
            }
        }

        vector<vector<int>>ans;

        for(auto [key,val]:mp){

            if(val.size()>1){
                sort(val.begin(),val.end());

                vector<int>temp;

                for(auto &x:val) temp.push_back(x.second);

                ans.push_back(temp);
            }
            else{

            vector<int>temp;

            for(auto &x:val) temp.push_back(x.second);
            ans.push_back(temp);
            }
        }

        return ans;



        

    }
};
