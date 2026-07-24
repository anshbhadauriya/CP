/*
just make recursive tree first and it will become simple
*/
class Solution {
public:
int n;
vector<string>ans;
void solve(int i,string &curr,unordered_map<int,string>&mp,string &digits){

    if(i>=n){
        ans.push_back(curr);
        return;
    }

    for(auto &x:mp[digits[i]-'0']){
        curr.push_back(x);
        solve(i+1,curr,mp,digits);
        curr.pop_back();
    }
}



    vector<string> letterCombinations(string digits) {

        if(digits.empty()) return {};

        n=digits.size();

        unordered_map<int,string>mp={{1,""},{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},
        {7,"pqrs"},{8,"tuv"},{9,"wxyz"} };

        string curr="";

        solve(0,curr,mp,digits);

        return ans;
    }
};
/*
level 0 -> 1 recursive call
level 1 -> maximum 4 rec call
level 2 -> 4^2 rec call

so ek level pr max 4^n call hogi
1+4+4^2+⋯+4^n== O(4^n)

aur har bar we are pushing curr to ans so O(n)

TC-> O(n.4^n)
SC-> O(n)
*/
