/*
UNINTUITIVE PROBLEM
numbers ko ek stack me dalo (number stack)
baki sab ko dusre stack me (string stack)
jabhi closing bracket aae so keep poping from string stack and combine them until u get opening bracket
abh jo combine krne ke baad usse concatenate kro numberstack.top() times abd then jo string bne usse string stack me dalo

yhi krte rho aur string stack me final answer aajaea
*/
class Solution {
public:
    string decodeString(string s) {
        
        stack<int>numStack;
        stack<string>stringStack;
        int k = 0;

        for(char c:s) {

            if(isdigit(c)){
                k=(k*10)+(c-'0');
                continue;
            }

            if(c=='['){
                numStack.push(k);
                k=0;
                stringStack.push("[");
                continue;
            }

            if(c!=']') {
                string temp="";
                temp+=c;  //char ko string me convert kro
                stringStack.push(temp);
                continue;
            }

            string temp="";

            while(stringStack.top()!="[") {
                temp=stringStack.top()+temp;
                stringStack.pop();
            }

            //remove "["
            stringStack.pop();

             //new string bnao
            string replacement = "";
            int count = numStack.top();
            numStack.pop();

            for(int i=0;i<count;i++){
                replacement+=temp;
            }

            stringStack.push(replacement);
        }

        string result="";

        while(!stringStack.empty()) {
            result=stringStack.top()+result;
            stringStack.pop();
        }

        return result;
    }
};
