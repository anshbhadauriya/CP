Q1->
  class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        vector<int>mp(26,0);
        int j=0;
        
        
        for(int i=0;i<26;i++){
            mp[i]=weights[j];
            j++;
        }

        string result;
        for(auto curr: words){

            int sum=0;

            for(int i=0;i<curr.size();i++){
                sum+=mp[curr[i]-'a'];
            }

            int moddd=sum%26;

            int idx;
            

            char ele='z'-moddd;
            
            result.push_back(ele);
        }
        return result;
    }
};


Q2->


  class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {

        unordered_map<string,int>mp;
        int maximum=0;

        for(int i=0;i<words.size();i++){
            
          string curr=words[i];
            if(curr.size()<k) continue;
            mp[curr.substr(0,k)]++;
        }
        for(auto x:mp){
            if(x.second>=2) maximum++;
        }
        return maximum;
        
    }
};


Q3->

  class Solution {
public:
    long long solve(int i,vector<int>&nums,vector<int>&colors,bool prev,vector<vector<long long>>&dp){
        if(i==nums.size()) return 0;

        if(dp[i][prev]!=-1) return dp[i][prev];
        
            if(!prev or (prev and colors[i]!=colors[i-1])){  //yaa too first element nhi lia ho yaa too first element lia and first != second 
             long long take=nums[i]+solve(i+1,nums,colors,true,dp);
            long long skip=solve(i+1,nums,colors,false,dp);
            return dp[i][prev]=max(take,skip);
        }

        else{
            return dp[i][prev]=solve(i+1,nums,colors,false,dp);
        }

        

        
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        vector<vector<long long>>dp(nums.size(),vector<long long>(2,-1));
        return solve(0,nums,colors,false,dp);
    }
};

  
