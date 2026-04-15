class Solution {
public:
set<string>ans;
void solve(int i,string curr,string &s){

    if(i==s.size()){
        ans.insert(curr);
        return;
    }
    
    curr+=tolower(s[i]);
    solve(i+1,curr,s);
    curr[curr.size()-1]=toupper(curr[curr.size()-1]);
    solve(i+1,curr,s);
}
    vector<string> letterCasePermutation(string s) {

        solve(0,"",s);

        vector<string>res;
        for(auto x:ans) res.push_back(x);
        return res;
        
    }
};
