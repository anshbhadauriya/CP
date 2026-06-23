/*

next smaller ele

prev smaller ele

inn dono ke bich jitne bhi ele honge will be >=height[i]

so next smaller - prev smaller -1
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n=heights.size();
        stack<int>st1,st2;
        vector<int>nums1(n),nums2(n);

        //next min find kro from right to left
        for(int i=n-1;i>=0;i--){

            while(!st1.empty() and heights[i]<=heights[st1.top()]){
                st1.pop();
            }

            if(!st1.empty()) nums1[i]=st1.top();

            else nums1[i]=n;

            st1.push(i);
        }

        //next min find kro from left to right

        for(int i=0;i<n;i++){

            while(!st2.empty() and heights[i]<=heights[st2.top()]){
                st2.pop();
            }

            if(!st2.empty()) nums2[i]=st2.top();
            else nums2[i]=-1;

            st2.push(i);
        }

        int maximum=0;

 

        for(int i=0;i<n;i++){

            int next_smaller_idx=nums1[i];
            int prev_smaller_idx=nums2[i];
            int breadth=next_smaller_idx - prev_smaller_idx -1 ;

            if(breadth<=0) breadth=1;
            int area=heights[i] * breadth;

            maximum=max(maximum,area);

     

        }

        return maximum;

        
    }
};

/*
Worse case me har ele ek bar push hoga ek bar pop so in both nge and pge

O(2n) + O(2n) + O(n)

TC=O(n)

SC->2 stacks 2 vector so O(n)
*/
