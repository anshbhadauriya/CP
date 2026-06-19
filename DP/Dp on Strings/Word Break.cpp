/*
check each word is in worddDict or not 

if it is present so 2 possibilities
    string formed till now will be new string 
    ignore and continue

if it is not present keep going

dp[i] mtlb Can the substring starting from index i be successfully broken into dictionary words?

Example
s = "leetcode"

Indexes:

l e e t c o d e
0 1 2 3 4 5 6 7

Suppose:

dp[4]

Then you're asking:

code
^^^^
index 4

Can "code" be formed from dictionary words?

If yes:

dp[4] = true;
*/

class Solution {
public:

unordered_set<string>st;

vector<int>dp;

bool solve(int i,string curr,string &target,vector<string>&wordDict){

    // cout<<" curr is ->>"<< curr<<endl;

    if(curr.size()>target.size()) return false;

    if(curr==target) return true;

    if(dp[i]!=-1) return dp[i];


    string temp="";
    int j=i;
    while(j<target.size()){

        temp+=target[j];

        


        if(st.count(temp)){  //2 possibilities

        // cout<<temp<<" "<<endl;

        

        if(dp[i]=solve(j+1,curr+temp,target,wordDict)) return true;

        }
        j++;
    }

    return dp[i]=false;

}
    bool wordBreak(string s, vector<string>& wordDict) {

        for(auto &x:wordDict) st.insert(x);

        string curr="";

         dp.resize(s.size(),-1);

        return solve(0,curr,s,wordDict);
        
    }
};
