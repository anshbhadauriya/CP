class Solution {
public:
vector<int>dp1;
vector<vector<int>>dp2;
bool isValid(int k,int j,string &s){


//cout<<s<<" ";

if(dp2[k][j]!=-1) return dp2[k][j];
    string temp=s.substr(k,j-k+1);

    if(temp.size()>2) return dp2[k][j]=false;

    if(temp.front()=='0') return dp2[k][j]=false;

    int num=stoi(temp);

    if(num>=1 and num<=26) return dp2[k][j]=true;

    return dp2[k][j]=false;
}

int solve(int idx,string &s){


    if(idx>=s.size()){
        return 1;
    }
    int ans=0;

    if(dp1[idx]!=-1) return dp1[idx];
    for(int i=idx;i<s.size();i++){

        if(isValid(idx,i,s)){
        ans+=solve(i+1,s);
        }
        
    }

    return dp1[idx]=ans;
}
    int numDecodings(string s) {

        if(s.front()=='0') return 0;

        dp1.resize(s.size(),-1);
        dp2.resize(s.size(),vector<int>(s.size(),-1));
        return solve(0,s);
        
    }
};
