class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        vector<int>result;
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }

        result.push_back(pq.top().first);
        int h=k;
        while(h<nums.size()){

            pq.push({nums[h],h});
            while(pq.top().second<h+1-k){
                pq.pop();
               
            }
            result.push_back(pq.top().first);
            h++;
        }
        return result;
    }
};