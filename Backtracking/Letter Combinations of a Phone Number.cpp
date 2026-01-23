class Solution {   //zyda smjh nhi aayaa
public:
void solve(int idx,string &curr,vector<string>&str,vector<string>&answer){
    if(idx==str.size()){
    answer.push_back(curr);
    return;
    }

    for(auto x:str[idx]){
        curr.push_back(x);
        solve(idx+1,curr,str,answer);
        curr.pop_back();
    }

}
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string>mp={{1,""},{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},
    
        {7,"pqrs"},{8,"tuv"},{9,"wxyz"}
        
        };
        vector<string>answer;
        vector<string>str;
        for(auto &x:digits){
            str.push_back(mp[x-'0']);
        }
        string curr="";
        solve(0,curr,str,answer);
        return answer;
    }
};
