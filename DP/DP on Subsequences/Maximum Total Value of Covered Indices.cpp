class Solution {
public:

/*
Yaa too curr lo

Yaa too prev lo (if prev was not taken)
*/

vector<vector<long long>>dp;

long long solve(int curr,int prev,vector<int>&nums,string &s){

    if(curr==nums.size()) return 0;

    if(dp[curr][prev]!=-1) return dp[curr][prev];
    
    long long ans;

    if(s[curr]=='0'){  //agr curr 0 hai too always skip
    ans=solve(curr+1,0,nums,s);
    }

    else{ 
        if(curr==0 or prev){ //curr=0 and s[curr]=1  yaa fir s[curr]==1 and prev
        ans=nums[curr]+solve(curr+1,1,nums,s);
    }

    else{  //now either take curr or prev

        long long take_curr=nums[curr]+solve(curr+1,1,nums,s);

        long long take_prev=nums[curr-1]+solve(curr+1,0,nums,s); //prev lelo curr wala nhi

        ans=max(take_curr,take_prev);
    }

    }

    return dp[curr][prev]=ans;

}
    long long maxTotal(vector<int>& nums, string s) {

        /*
        if prev is 0 so we have 2 choices
        make prev 1 and curr 0
        keep same
        
        */

        int n=nums.size();

        dp.resize(n,vector<long long>(2,-1));
         
        // if(s.front()=='1') ans+=nums.front();

         return solve(0,0,nums,s);
    }
};
