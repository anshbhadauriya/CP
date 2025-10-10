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