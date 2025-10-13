Recursive->

class Solution {
public:
int solve(string text1,string text2,int i,int j){
    if(i==0 or j==0){
        return 0;
    }
    if(text1[i-1]==text2[j-1]){
        return 1+solve(text1,text2,i-1,j-1);
    }
    else{
        return max(solve(text1,text2,i-1,j),solve(text1,text2,i,j-1));
    }
}
    int longestCommonSubsequence(string text1, string text2) {
        int i=text1.size();
        int j=text2.size();
        
       return solve(text1,text2,i,j);
    }

};


Memoized->


    class Solution {
public:
int solve(string text1,string text2,int i,int j,vector<vector<int>>&dp){
    if(i==0 or j==0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(text1[i-1]==text2[j-1]){
        return dp[i][j]=1+solve(text1,text2,i-1,j-1,dp);
    }
    else{
        return dp[i][j]=max(solve(text1,text2,i-1,j,dp),solve(text1,text2,i,j-1,dp));
    }
}
    int longestCommonSubsequence(string text1, string text2) {
        int i=text1.size();
        int j=text2.size();
        vector<vector<int>>dp(i+1,vector<int>(j+1,-1));
        
       return solve(text1,text2,i,j,dp);
    }
};

Tabulation->

    class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 or j==0){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(text1[j-1]==text2[i-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[m][n];

    }
};



