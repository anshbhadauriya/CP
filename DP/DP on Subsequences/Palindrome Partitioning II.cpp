/*
so intuition is 

agr iterate krte hue palindrome bane string left wali soo wha se break kro aur uss break ki
cost ++ krdo  

abh ek break hogya lekin maybe in future bhi usss substring ko break krna bde so 

usme bhi same process kro 

so har point pr left substring break when palindrome is found

aur do same for right 

and keep a track of total cost
*/

class Solution {
public:

vector<int>dp;
vector<vector<int>>dp2;

bool isPalindrome(string &s,int l,int h){

    if(l>=h) return true;

     if(dp2[l][h]!=-1) return dp2[l][h];

   if(s[l]!=s[h])  return dp2[l][h]=false;


   return dp2[l][h]=isPalindrome(s,l+1,h-1);


}


int solve(string &s , int i){

if(i>=s.size()) return 0;
if(dp[i]!=-1) return dp[i];
int minimum=INT_MAX;
    for(int j=i;j<s.size();j++){

        if(isPalindrome(s,i,j)){
            minimum=min(minimum,1+solve(s,j+1));
        }
    }

    return dp[i]=minimum;
}
    int minCut(string s) {
        dp.resize(s.size()+1,-1);
        dp2.resize(s.size()+1,vector<int>(s.size()+1,-1));

        return solve(s,0)-1; //-1 bcs ek ele zabardasti break kro

       
        
    }
};

// TC -> O(n²)
// SC -> O(n²)
