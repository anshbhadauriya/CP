class Solution {
public:
int dp[601][101][101];
int solve(int idx,vector<string>& strs, int &m, int &n,vector<int>&ones,vector<int>&zeros,int curr_ones,int curr_zeros){

    if(curr_ones>n or curr_zeros>m) return INT_MIN;

    if(idx>=strs.size()){
        return 0;
    }

    if(dp[idx][curr_zeros][curr_ones]!=-1) return dp[idx][curr_zeros][curr_ones];

    int take=INT_MIN,skip=INT_MIN;

    take=1+solve(idx+1,strs,m,n,ones,zeros,curr_ones+ones[idx],curr_zeros+zeros[idx]);

    skip=solve(idx+1,strs,m,n,ones,zeros,curr_ones,curr_zeros);

    return dp[idx][curr_zeros][curr_ones]=max(take,skip);
}
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sizee=strs.size();
        vector<int>ones(strs.size(),0),zeros(strs.size(),0);

        for(int i=0;i<sizee;i++){

            int o=0,z=0;
            for(int j=0;j<strs[i].size();j++){

                if(strs[i][j]=='1') o++;
                else z++;
            }

            ones[i]=o;
            zeros[i]=z;
        }

        memset(dp,-1,sizeof(dp));
        return solve(0,strs,m,n,ones,zeros,0,0);


    }
};
