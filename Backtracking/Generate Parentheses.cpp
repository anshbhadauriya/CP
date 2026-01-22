class Solution {
public:
void solve(int n,string current,vector<string>&result,int open,int close){
    if(open==n and close==n){
        result.push_back(current);
        return;
    }
    if(open < n){
    solve(n,current+'(',result,open+1,close);
    }
    if(close<open){
    solve(n,current+')',result,open,close+1);
    }

}
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        int idx=0,open=0,close=0;
        string current;
        solve(n,current,result,0,0);
        return result;
    }
};