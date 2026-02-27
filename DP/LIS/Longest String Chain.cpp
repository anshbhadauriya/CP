Recursive->

class Solution {
public:

//take 
//not take
//if take so check is it predecessor of prev

//how to check curr string is predecessor of prev?
//check that manually 
int maximum=1;

bool ispred(string &prev,string &curr){
    if(curr.size()-prev.size()!=1) return false;

    int i=0,j=0,not_equal=0;

    while(i<prev.size() and j<curr.size()){
        if(prev[i]!=curr[j]){
            not_equal+=1;
            if(not_equal>1) return false;
            j++;
        }
        else{
            i++;
            j++;
        }
    }
   if(j<curr.size()) not_equal++;

    return not_equal==1;
}
void solve(int i,string prev,vector<string>& words,int count){

    if(i==words.size()){
        maximum=max(maximum,count);
        return;
    }

    if(prev.empty()){
        solve(i+1,words[i],words,count+1);  //take
        solve(i+1,prev,words,count);  //skip
    }

    else{

        //2 choices take kro ya skip lekin take tabhi hoga jab predecessor hoga

        if(ispred(prev,words[i])){
            solve(i+1,words[i],words,count+1);  //take
        }
        solve(i+1,prev,words,count);
    }
}
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),  //size wise sorting
     [](string &a,string &b){
         return a.size()<b.size();
     });
        string curr="";
        solve(0,curr,words,0);
        return maximum;
        
    }
};

Memoized->

class Solution {
public:

//take 
//not take
//if take so check is it predecessor of prev

//how to check curr string is predecessor of prev?
//check that manually 
//recursion worked now dp
//states-> i,prev,curr,count
int maximum=1;
vector<vector<int>>dp;
bool ispred(string &prev,string &curr){
    if(curr.size()-prev.size()!=1) return false;

    int i=0,j=0,not_equal=0;

    while(i<prev.size() and j<curr.size()){
        if(prev[i]!=curr[j]){
            not_equal+=1;
            if(not_equal>1) return false;
            j++;
        }
        else{
            i++;
            j++;
        }
    }
   if(j<curr.size()) not_equal++;

    return not_equal==1;
}
int solve(int i,int prev_idx,vector<string>& words){

    if(i==words.size()){
        return 0; 
    }
    if(dp[i][prev_idx+1]!=-1) return dp[i][prev_idx+1];

    int take=0;

    if(prev_idx==-1 || ispred(words[prev_idx],words[i])){
        take=1+solve(i+1,i,words);
    }

    int skip=solve(i+1,prev_idx,words);

    return dp[i][prev_idx+1]=max(take,skip);
}
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),  //size wise sorting
     [](string &a,string &b){
         return a.size()<b.size();
     });

     int n=words.size();
    dp.assign(n,vector<int>(n+1,-1));

        int pre_idx=-1;
        return solve(0,-1,words);
        
        
    }
};
