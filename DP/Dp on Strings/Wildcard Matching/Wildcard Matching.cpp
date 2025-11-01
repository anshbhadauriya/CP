Recursive->

class Solution {
public:
bool solve(string &s,string &p,int i,int j){
    if(i<0 and j<0){
        return true;
    }
    if(i<0 and j>=0){
        for(int idx=0;idx<=j;idx++){
            if(p[idx]!='*'){
                return false;
            }
        }
        return true;
    }
    if(j<0 and i>=0){
        return false;
    }

    if(s[i]==p[j] or p[j]=='?'){
       return solve(s,p,i-1,j-1);
    }
    if(p[j]=='*'){
        return solve(s,p,i-1,j) || solve(s,p,i,j-1);
    }
    return false;

}
    bool isMatch(string s, string p) {
        int i=s.size()-1;
        int j=p.size()-1;
        return solve(s,p,i,j);
    }
};


Memoization->

class Solution {
public:
bool solve(string &s,string &p,int i,int j,vector<vector<int>>&dp){
    if(i<0 and j<0){
        return true;
    }
    if(i<0 and j>=0){
        for(int idx=0;idx<=j;idx++){
            if(p[idx]!='*'){
                return false;
            }
        }
        return true;
    }
    if(i>=0 and j<0){
        return false;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(s[i]==p[j] or p[j]=='?'){
       return dp[i][j]=solve(s,p,i-1,j-1,dp);
    }
    if(p[j]=='*'){
        return dp[i][j]=solve(s,p,i-1,j,dp) || solve(s,p,i,j-1,dp);
    }
    return dp[i][j]=false;

}
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        int i=s.size()-1;
        int j=p.size()-1;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(s,p,i,j,dp);
    }
};


Tabulation->

