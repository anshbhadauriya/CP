Recursive->

class Solution {
public:
int solve(string &word1,string &word2,int i,int j){
    if(i<0){
        return j+1;
    }
    if(j<0){
        return i+1;
    }
    if(word1[i]==word2[j]){
        return solve(word1,word2,i-1,j-1);
    }

    int insert=1+solve(word1,word2,i,j-1);
    int deletee=1+solve(word1,word2,i-1,j);
    int update=1+solve(word1,word2,i-1,j-1);
    return min({insert,deletee,update});
}
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int i=n-1,j=m-1;
        return solve(word1,word2,i,j);
    }
};


Memoized->

class Solution {
public:
int solve(string &word1,string &word2,int i,int j,vector<vector<int>>&dp){
    if(i<0){
        return j+1;
    }
    if(j<0){
        return i+1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(word1[i]==word2[j]){
        return dp[i][j]=solve(word1,word2,i-1,j-1,dp);
    }

    int insert=1+solve(word1,word2,i,j-1,dp);
    int deletee=1+solve(word1,word2,i-1,j,dp);
    int update=1+solve(word1,word2,i-1,j-1,dp);
    return dp[i][j]=min({insert,deletee,update});
}
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int i=n-1,j=m-1;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(word1,word2,i,j,dp);
    }
};