class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        //y>x
        //x and y should be diff freq
        unordered_map<int,int>mp;
        for(auto x:nums) mp[x]++;
        sort(nums.begin(),nums.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<nums.size()-1;i++){
            int x=mp[nums[i]];
            for(int j=i+1;j<nums.size();j++){
                int y=mp[nums[j]];
                if(x!=y){
                    pq.push({nums[i],nums[j]});
                }
            }
        }
        if(pq.empty()) return {-1,-1};
        
        return {pq.top().first,pq.top().second};

        
    }
};

class Solution {
public:
    string mergeCharacters(string s, int k) {
        //lowercase letters
        //diff bw two same is atmost k then equal
        int j=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            bool found=false;
            int start=max(0,j-k);
            for(int p=start;p<j;p++){
                if(s[p]==s[i]){ found=true;
                break;
                              }
            }
        
        if(!found){
            s[j]=s[i];
            j++;
        }
    }
        return s.substr(0,j);
    }
};
