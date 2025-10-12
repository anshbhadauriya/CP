Q1->

class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        int sum=0;
        for(auto x:mp){
            if(x.second%k==0){
                sum=sum+x.first*x.second;
            }
        }
        return sum;
    }
};


Q2->

class Solution {
public:
    bool countfreq(vector<int>&mp){
        int freq=0;
       for(int i=0;i<mp.size();i++){
           if(mp[i]==0){
               continue;
           }
           if(freq==0){
               freq=mp[i];
           }
           if(freq!=mp[i]){
               return false;
           }
           
       }
        return true;
    }
    int longestBalanced(string s) {
        if(s.size()==1){
            return 1;
        }
        int maximum=0;
        for(int i=0;i<s.size()-1;i++){
            vector<int>mp(26, 0);
            for(int j=i;j<s.size();j++){
                int x=s[j]-'a';
                mp[x]++;
                if(countfreq(mp)){
                    maximum=max(maximum,j-i+1);
                }
            }
        }
        
        return maximum;
    }
};


