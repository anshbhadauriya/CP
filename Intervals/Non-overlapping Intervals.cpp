class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int count=0;

        sort(intervals.begin(),intervals.end());

        int prevL=INT_MIN,prevH=INT_MIN;


        for(auto x:intervals){
            if(prevL==INT_MIN and prevH==INT_MIN){
                prevL=x[0],prevH=x[1];
            }
            else{

                if(prevH>x[0]){  //overlap
                count++;

                if(x[1]<prevH) prevL=x[0],prevH=x[1];
                  //previous or curr me jiska endtime smaller ho usse rkho bcs vo jldi khtm hojaega
                 
                }
                else prevL=x[0],prevH=x[1];

            }

        }

        return count;
        
    }
};
