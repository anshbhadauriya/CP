/*
so basically we need to find
pairs of seq whose gcd is equal

so in each state we have 3 options:
take ele for seq1
take ele for seq2
skip
*/
class Solution {
public:
int dp[201][201][201];
int MOD=1e9+7;
int solve(int i,vector<int>&nums,int g1,int g2){

    if(i>=nums.size()){

        if(g1!=0 and g2!=0 and g1==g2) return 1;
        else return 0;
    }

    if(dp[i][g1][g2]!=-1) return dp[i][g1][g2];

    long long seq1=solve(i+1,nums,gcd(g1,nums[i]),g2);
    long long seq2=solve(i+1,nums,g1,gcd(g2,nums[i]));
    long long skip=solve(i+1,nums,g1,g2);

    return dp[i][g1][g2]=((seq1)%MOD+(seq2)%MOD+(skip)%MOD)%MOD;
}
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,0,0);  
        
    }
};
