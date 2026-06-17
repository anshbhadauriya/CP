class Solution {
public:
/*

st1+str2-LCS

*/
    string shortestCommonSupersequence(string str1, string str2) {

        int n=str1.size(),m=str2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int lcs_length=dp[n][m];

        cout<<lcs_length<<endl;

        string LCS="";

        int i=n,j=m;

        while(i>0 and j>0){

            if(str1[i-1]==str2[j-1]){

                LCS.push_back(str1[i-1]);
                
                i--;
                j--;
            }

            else if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }

        reverse(LCS.begin(),LCS.end());

        cout<<LCS<<endl;

        string ans="";
         
         i=0,j=0;

        for(auto c:LCS){

            //jab str1 aur str2 ke character lcs se match nhi horhe tab tk add krdo
            
            while(str1[i]!=c){
             ans.push_back(str1[i]);
             i++;
            }

            

            while(str2[j]!=c){
             ans.push_back(str2[j]);
             j++;
            }

            ans+=str1[i];  //abh jab dono same hai aur so add once

            i++; //ek bar bdha do dono ko
            j++; 
        }

        //bache hue character add krdo

        while(i<str1.size()){ ans.push_back(str1[i]); i++; }

        while(j<str2.size()){ ans.push_back(str2[j]); j++; }


        return ans;
        
    }
};
