class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        if(k==num.size()){
            return "0";
        }
        
        for(int i=0;i<num.size();i++){
            int curr=int(num[i]);
            if(st.empty()){
                st.push(curr);
                continue;
            }

            while(!st.empty() and st.top()>curr and k){
                st.pop();
                k--;
            }
            st.push(curr);
        }

        while(k--){
            st.pop();
        }
        

        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        while(ans.size()>=2 and ans.back()=='0'){
            ans.pop_back();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
