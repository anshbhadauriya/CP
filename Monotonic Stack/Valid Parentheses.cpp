class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            int curr=s[i];

            if(st.empty()){

                if(curr==')' or curr==']' or curr=='}'){
                    return false;
                }
                else{
                    st.push(curr);
                }
            }

            else if((st.top()=='(' and curr==')') or (st.top()=='[' and curr==']') or (st.top()=='{' and curr=='}')){
                st.pop();
            }
            else{
                st.push(curr);
            }

        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};
