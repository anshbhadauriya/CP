class Solution {
  public:

  void solve(Node* root,int cons,int &maximum){
      
      if(!root){
          
          return;
      }
      
      if(root->left and root->left->data-root->data==1){
          solve(root->left,cons+1,maximum);
      }
      else solve(root->left,1,maximum);
      
      if(root->right and root->right->data-root->data==1){
          solve(root->right,cons+1,maximum);
      }
      else solve(root->right,1,maximum);
      
    maximum=max(maximum,cons);  
  }
    int longestConsecutive(Node* root) {
          int maximum=0;
        solve(root,1,maximum);
        
        return (maximum==1)?-1:maximum;
    }
};
