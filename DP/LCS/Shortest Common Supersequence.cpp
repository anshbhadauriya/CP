summary-> text1+text2-LCS of text1 and text2

class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
         int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
          string scs="";
        int i=n,j=m;
        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){
                scs+=text1[i-1];
                i--; 
              j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                scs+=text1[i-1];
                i--;
            }
            else{
                scs+= text2[j-1];
                j--;
            }
        }

        while(i>0){
            scs+=text1[i-1];
             i--;
        }
        while(j>0) {
            scs+=text2[j-1];
         j--;
         }

        reverse(scs.begin(), scs.end());
        return scs;
    }

    
};
