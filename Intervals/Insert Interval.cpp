Brute force->

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        //push krdo new interval fir sort krdo fir merge interval wala code laga do
        intervals.push_back(newInterval);
         sort(intervals.begin(),intervals.end());

         //merge interval

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

Optimized->
  
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        int n=intervals.size();
        vector<vector<int>>result;

        //sbse pehle conflict find kro ki kis point par newInterval aaega
        while(i<n and intervals[i][1]<newInterval[0]){
            result.push_back(intervals[i]);
            i++;
        }

        //now you already know that conflict is started so now you have to make a new interval which extends upto which it stops conflictng with intervals

        int new_st=newInterval[0],new_end=newInterval[1];
        while(i<n and newInterval[1]>=intervals[i][0]){
             new_st=min(new_st,intervals[i][0]);
             new_end=max(new_end,intervals[i][1]);
             i++;
        }

        //abh new interval create ho chuka hai abh usse result me daldo

        result.push_back({new_st,new_end});

        //bache hue intervals ko result me daldo

        while(i<n){
            result.push_back(intervals[i]);
            i++;
        }

        return result;


    }
};
