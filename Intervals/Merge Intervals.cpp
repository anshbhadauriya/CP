class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        vector<vector<int>>result;
        int prev_end=-1,prev_start=-1;
        for(int i=0;i<intervals.size();i++){
            int start=intervals[i][0];
            int end=intervals[i][1];

           if(i==0){
            result.push_back({start,end});
            continue;
           }

           if(start<=result[result.size()-1][1]){
            result[result.size()-1][1]=max(end,result[result.size()-1][1]);
           }
           else{
            result.push_back({start,end});
           }


        }
        return result;
    }
};