class Solution {
public:
    string frequencySort(string s) {
        //descending order

        unordered_map<char,int>mp;
        for(auto &x:s) mp[x]++;

        priority_queue<pair<int,char>>pq;
        for(auto x:mp){
            pq.push({x.second,x.first});
        }

        string ans;

        while(!pq.empty()){
            int freq=pq.top().first;
            char ele=pq.top().second;
            for(int i=0;i<freq;i++){
                ans.push_back(ele);
            }
            pq.pop();
        }

        return ans;
    }
};
