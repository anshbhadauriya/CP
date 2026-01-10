class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 or j==0) continue;
                 if(s1[i-1]!=s2[j-1]){
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                 }
                 else{
                    dp[i][j]=s1[i-1]+dp[i-1][j-1];
                 }
            }
        }
        int lcs_asci_sum=dp[n][m];

        int s1_sum=0,s2_sum=0;

        for(int i=0;i<n;i++) s1_sum+=s1[i];
        for(int i=0;i<m;i++) s2_sum+=s2[i];
        

        return s1_sum+s2_sum-(2*lcs_asci_sum);


    }
};
