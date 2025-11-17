By monotonic stack->

  class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st,st2;
        vector<int>clone_r(height.begin(),height.end()),clone_l(height.begin(),height.end());
        for(int i=height.size()-1;i>=0;i--){
            while(!st.empty() and height[i]>st.top()){
                st.pop();
            }
            if(!st.empty() and height[i]<st.top()){
                clone_r[i]=st.top();
            }
            st.push(clone_r[i]);
        }

        

        for(int i=0;i<height.size();i++){
            while(!st2.empty() and height[i]>st2.top()){
                st2.pop();
            }
            if(!st2.empty() and height[i]<st2.top()){
                clone_l[i]=st2.top();
            }
            st2.push(clone_l[i]);
        }
        int count=0;
        for(int i=0;i<height.size();i++){
            int minimum=min(clone_l[i],clone_r[i]);
            count=count+abs(height[i]-minimum);
        }

        return count;

    }
};


By using vector->

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>left(height.begin(),height.end()),right(height.begin(),height.end());
        int maxii=INT_MIN;
        for(int i=0;i<left.size();i++){
            maxii=max(maxii,left[i]);
            left[i]=maxii;
        }

        maxii=INT_MIN;

        for(int i=right.size()-1;i>=0;i--){
            maxii=max(maxii,right[i]);
            right[i]=maxii;
        }

        int count=0;
        for(int i=0;i<height.size();i++){
            int diff=min(left[i],right[i]);
            count=count+abs(height[i]-diff);
        }
        return count;
    }
};
