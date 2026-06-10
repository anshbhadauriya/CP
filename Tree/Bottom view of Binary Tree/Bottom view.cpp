/*

Simple hai bss copy me tree banao aur usme upr se vertical levels banao

left side wale ele ko -ve kro right walo ko +ve  aur map me dalo

bss diagram dekh lo apne aap smjh aajaega

*/
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        
        map<int,int>mp;
        
        queue<pair<Node*,int>>q;
        
        q.push({root,0});
        
        while(!q.empty()){
            Node* curr=q.front().first;
            int number=q.front().second;
            q.pop();
            
            mp[number]=curr->data;
            
            if(curr->left) q.push({curr->left,number-1});
            if(curr->right) q.push({curr->right,number+1});
            
        }
        
        vector<int>ans;
        
        for(auto x:mp) ans.push_back(x.second);
        
        return ans;
        
    }
};
