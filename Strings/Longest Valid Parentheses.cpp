class Solution {
public:
    int longestValidParentheses(string s) {

        int open=0,close=0,maximum=0;

        for(auto x:s){
            if(x=='(') open++;
            else close++;
            if(close>open){  //invalid
                close=0;
                open=0;
            }
            else if(open==close)
            maximum=max(maximum,open+close);
        }

       //abh same cheez right to left to left krna hai too abh open wale ko close consider kro

       open=0,close=0;

       for(int i=s.size()-1;i>=0;i--){
        char x=s[i];

        if(x==')') open++;
            else close++;
            if(close>open){  //invalid
                close=0;
                open=0;
            }
            else if(open==close)
            maximum=max(maximum,open+close);


       }



        return maximum;        
    }
};
