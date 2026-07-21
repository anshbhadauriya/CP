class Solution {
public:
int n;
vector<vector<int>>dp1; //for answers

vector<vector<int>>dp2; //for palindrome
bool isPalindrome(int a,int b,string &s){

    if(dp2[a][b]!=-1) return dp2[a][b];

int l=a,h=b;
    while(l<h){

        if(s[l]!=s[h]) return dp2[a][b]=false;
        l++;
        h--;
    }

    return dp2[a][b]=true;
}

int solve(int idx,int partition,string &s){

    if(idx>=s.size()) return false;

    if(dp1[idx][partition]!=-1) return dp1[idx][partition];

    if(partition==2){

        if(isPalindrome(idx,n-1,s)) return dp1[idx][partition]=true;

        else return dp1[idx][partition]=false;
    }



    for(int j=idx;j<n;j++){


        if(isPalindrome(idx,j,s)){

             if(solve(j+1,partition+1,s)) return dp1[idx][partition]=true;
        }
    }

    return dp1[idx][partition]=false;

}
    bool checkPartitioning(string s) {

        n=s.size();

        dp1.resize(n,vector<int>(4,-1));

        dp2.resize(n+1,vector<int>(n+1,-1));

        return solve(0,0,s);
        
    }
};
