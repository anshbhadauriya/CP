class Solution {
  public:
    vector<int> topView(Node *root) {
        
        
        map<int,int>mp;
        
        queue<pair<Node*,int>>q;
        
        q.push({root,0});
        
        while(!q.empty()){
            Node* curr=q.front().first;
            int number=q.front().second;
            q.pop();
            
            if(!mp.count(number))
            mp[number]=curr->data;
            
            if(curr->left) q.push({curr->left,number-1});
            if(curr->right) q.push({curr->right,number+1});
            
        }
        
        vector<int>ans;
        
        for(auto x:mp) ans.push_back(x.second);
        
        return ans;
        
        
    }
};
