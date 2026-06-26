class Solution {
public:

/*
answer[i]=> current temperature se zyda temperature kitne din baad aaega

hella easy

just find next greater ele 
*/
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n=temperatures.size();
        stack<int>st;
        vector<int>ans(n,0);

        for(int i=n-1;i>=0;i--){

            while(!st.empty() and temperatures[i]>=temperatures[st.top()])
            st.pop();

            if(!st.empty()) ans[i]=st.top()-i; 

            st.push(i);
        }

        return ans;
        
    }
};

/*
TC-> O(n)
SC->0(n)
*/
