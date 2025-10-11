https://www.youtube.com/watch?v=-ToUWP1Yxzo    

Recursive->

class Solution {
  public:
  int solve(string& s1, string& s2,int i,int j,int count){
      if(i==s1.size() or j==s2.size()){
          return count;
      }
      int inc=0;
      if(s1[i]==s2[j]){
          inc=solve(s1,s2,i+1,j+1,count+1);
      }
      int ex1=solve(s1,s2,i+1,j,0);
      int ex2=solve(s1,s2,i,j+1,0);
      return max({inc,ex1,ex2});
      
  }
    int longestCommonSubstr(string& s1, string& s2) {
        return solve(s1,s2,0,0,0);
        
    }
};

Memoization->


class Solution {
  public:
  int solve(string& s1, string& s2,int i,int j,int count,vector<vector<vector<int>>>&dp){
      if(i==s1.size() or j==s2.size()){
          return count;
      }
      if(dp[i][j][count]!=-1){
          return dp[i][j][count];
      }
      int inc=0;
      if(s1[i]==s2[j]){
          inc=solve(s1,s2,i+1,j+1,count+1,dp);
      }
      int ex1=solve(s1,s2,i+1,j,0,dp);
      int ex2=solve(s1,s2,i,j+1,0,dp);
      return dp[i][j][count]=max({inc,ex1,ex2});
      
  }
    int longestCommonSubstr(string& s1, string& s2) {
        int k=min(s1.size(), s2.size());
        int n=s1.size();
        int m=s2.size();

        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return solve(s1,s2,0,0,0,dp);
        
    }
};
