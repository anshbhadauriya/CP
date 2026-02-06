class Solution {
public:
    int myAtoi(string s) {

        //front spaces remove kro
        //if first digit is - so -ve else +ve
        //if no digit found return 0

        if(s.empty()) return 0;

        while(!s.empty() && s.front()==' '){
            s.erase(s.begin());
        }
        if(s.empty()) return 0;
        int i=0;
        int sign = 1;
        if(s[i]=='+') {
            i++;
        } else if(s[i]=='-') {
            sign=-1;
            i++;
        }

        long long res=0;

        while(i<s.size() and isdigit(s[i])){
            int digit=s[i]-'0';
            res=res*10+digit;

            if(sign*res<=INT_MIN) return INT_MIN;

            if(sign*res>=INT_MAX) return INT_MAX;

            i++;
        }

        return res*sign;
    }
};