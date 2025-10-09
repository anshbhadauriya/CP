class Solution {
  public:
    vector<int> topView(Node *root) {
        if(!root){
            return {};
            }
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            Node* temp=q.front().first;
            int value=q.front().second;
            if(mp.find(value)==mp.end()){
                mp[value]=temp->data;
            }
            q.pop();
            if(temp->left){
                q.push({temp->left,value-1});
            }
            if(temp->right){
                q.push({temp->right,value+1});
            }
        }
        vector<int>answer;
        for(auto x:mp){
            answer.push_back(x.second);
        }
        return answer;
        
    }
};