Constraints are very small so brute force will also work 

Brute Force->
class Solution {
public:
bool ispalindrome(string &s,int i,int j){
    if(i>=j) return true;

    if(s[i]==s[j]){
        return ispalindrome(s,i+1,j-1);
    }
    else{
        return false;
    }

}
    string longestPalindrome(string s) {
        int maximum=0,st=-1,end=-1;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(ispalindrome(s,i,j)){
                    maximum=max(maximum,j-i+1);
                    if(maximum==j-i+1){
                        st=i;
                        end=j;
                    }
                }
            }
        }

        return s.substr(st,end-st+1);

        
    }
};

Memoized->

class Solution {
public:
bool ispalindrome(string &s,int i,int j,vector<vector<int>>&dp){
   
    if(i>=j) return 1;
    
     if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==s[j]){
        return dp[i][j]=ispalindrome(s,i+1,j-1,dp);
    }
    else{
        return dp[i][j]=0;
    }

}
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int maximum=0,st=-1,end=-1;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(ispalindrome(s,i,j,dp)){
                    maximum=max(maximum,j-i+1);
                    if(maximum==j-i+1){
                        st=i;
                        end=j;
                    }
                }
            }
        }

        return s.substr(st,end-st+1);

        
    }
};
