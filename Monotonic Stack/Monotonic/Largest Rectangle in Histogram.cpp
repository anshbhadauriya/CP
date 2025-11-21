class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nse(heights.size(),heights.size()),pse(heights.size(),-1);
        stack<pair<int,int>>st1,st2;
        for(int i=0;i<heights.size();i++){
            while(!st1.empty() and st1.top().first>=heights[i]){
                st1.pop();
            }
            if(!st1.empty()){
                pse[i]=st1.top().second;
            }
            st1.push({heights[i],i});
        }
        for(int i=heights.size()-1;i>=0;i--){
            while(!st2.empty() and st2.top().first>=heights[i]){
                st2.pop();
            }
            if(!st2.empty()){
                nse[i]=st2.top().second;
            }
            st2.push({heights[i],i});
        }
        int maximum=0;
        for(int i=0;i<heights.size();i++){
            int rectangle=heights[i]*(nse[i]-pse[i]-1);
            maximum=max(maximum,rectangle);
        }

        return maximum;
    }
};
