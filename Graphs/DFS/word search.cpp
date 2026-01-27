class Solution {
  public:
    bool dfs(vector<vector<char>> &mat, vector<vector<bool>> &vis, int i, int j, string &word,int idx){
        int n=mat.size();
        int m=mat[0].size();
        if(idx==word.size()){
            return true;
        }
        
        vis[i][j] = true;
       if(i-1>=0 and mat[i-1][j]==word[idx] and !vis[i-1][j]){
           if(dfs(mat,vis,i-1,j,word,idx+1)) return true;;
       }
       if(i+1<n and mat[i+1][j]==word[idx] and !vis[i+1][j]){
           if(dfs(mat,vis,i+1,j,word,idx+1)) return true;;
       }
       if(j-1>=0 and mat[i][j-1]==word[idx] and !vis[i][j-1]){
           if(dfs(mat,vis,i,j-1,word,idx+1)) return true;
       }
       if(j+1<m and mat[i][j+1]==word[idx] and !vis[i][j+1]){
           if(dfs(mat,vis,i,j+1,word,idx+1)) return true;;
       }
       
        vis[i][j] = false;
        return false;
    }
  
    bool exist(vector<vector<char>> &mat, string word) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int idx=0;
        
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] and mat[i][j]==word[idx]){
                    if(dfs(mat,vis,i,j,word,idx+1)) return true;
                }
            }
        }
        
        return false;
        
    }
};
