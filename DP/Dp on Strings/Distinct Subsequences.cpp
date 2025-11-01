Recursive->

class Solution {
public:
int solve(string s,string t,int i,int j){
    if(j<0){
        return 1;
    }
    if(i<0){
        return 0;
    }
    if(s[i]==t[j]){
        return solve(s,t,i-1,j-1)+solve(s,t,i-1,j);
    }
    else{
        return solve(s,t,i-1,j);
    }
}
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        int i=n-1,j=m-1;
        return solve(s,t,i,j);
    }
};


Memoization->

class Solution {
public:
int solve(string s,string t,int i,int j){
    if(j<0){
        return 1;
    }
    if(i<0){
        return 0;
    }
    if(s[i]==t[j]){
        return solve(s,t,i-1,j-1)+solve(s,t,i-1,j);
    }
    else{
        return solve(s,t,i-1,j);
    }
}
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        int i=n-1,j=m-1;
        return solve(s,t,i,j);
    }
};


Tabulation->

class Solution {
public:
const int MOD = 1e9 + 7;
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));
        for (int i=0;i<=n;i++) dp[i][0]=1;


        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(s[i-1]==t[j-1])
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]) % MOD;
                else
                    dp[i][j]=dp[i-1][j];
            }
        }

        return dp[n][m];
    }
};