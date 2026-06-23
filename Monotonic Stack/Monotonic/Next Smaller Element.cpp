class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        
        int n=arr.size();
        stack<int>st;
        
        vector<int>ans(n);
        
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() and arr[i]<=st.top()){
                st.pop();
            }
            
            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
            
            st.push(arr[i]);
        }
        
        return ans;
        
    }
};
