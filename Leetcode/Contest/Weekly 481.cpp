Q1->
  class Solution {
public:
    int mirrorDistance(int n) {
        string num=to_string(n);
        reverse(num.begin(),num.end());
        int nn=stoi(num);
        return abs(nn-n);
    }
};

Q2->
  class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        unordered_map<char,long long>mp;
        long long maximum=0,total=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]+=cost[i];
            total=total+cost[i];
            if(mp[s[i]]>maximum){
                    maximum=mp[s[i]];
                }
            
        }
        return total-maximum;
    }
};
