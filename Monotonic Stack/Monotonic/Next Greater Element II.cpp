class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>answer(n,-1);
        for(int i=2*(n-1);i>=0;i--){
            int idx=i%n;

            while(!st.empty() and nums[idx]>=st.top()){
                st.pop();
            }

            if(st.empty()){
                answer[idx]=-1;
            }
            else{
                answer[idx]=st.top();
            }
            st.push(nums[idx]);


        }
        return answer;
    }
};
