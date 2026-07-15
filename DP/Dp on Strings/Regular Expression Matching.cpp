/*

. = any one character

* = zero or more of the previous element

so mtlb agr * aarha too * ke piche wale ele ko kitni bar bhi consider kr skte ho

match kro aage bdo

if its * u have choice take it or not take it

important observations:

agr kabhi * mile too check ele before *
2 options:
ya too * ke piche koi ele hoga
yaa too * ke piche . hoga

now u have choice ki * ke pehle wale ele ko kitni bar le
agr 0 times lia -> pattern.substr(2)  kyuki 2 ele skip hogae so we just removed 2 ele from pattern

ham string pattern ko change krte ja rhe hai

to take a ele check:
yaa too s[i]==p[i]
yaa fir s[0]==. and p[i] is some ele



*/
class Solution {
public:
int n,m;
bool solve(string s,string p){
    if(p.empty() and s.empty()) return true;

    bool first_char_matched=false;

    if(!s.empty() and (p[0]==s[0] or p[0]=='.')) first_char_matched=true;

    /*
    yaa too skip yaa fir take 
    take tbhi krege jab first character . ho aur curr second * 
    
    lets take a example
    s = "aaab"
    p = "a*b"

    now when we are at idx 0 so we have two choice either skip this a* (we can skip bcs * means ki 0 or more time le skte ho) kyuki kya pta a* ke baad aaab ho 
    */ 

    if(p.size()>=2 and p[1]=='*'){
        return solve(s,p.substr(2)) or (first_char_matched and solve(s.substr(1),p));
    }
    else{
        /*
just check curr ele
s = "abc"
p = "abc"

a == a?   ← hum sirf current check karte hain
   ↓
solve("bc", "bc")

b == b? 
   ↓
solve("c", "c")

c == c? 
   ↓
solve("", "")

TRUE
        
        */
        return first_char_matched and solve(s.substr(1),p.substr(1));

    }
}
    bool isMatch(string s, string p) {
        n=s.size(),m=p.size();
        return solve(s,p);
        
    }
};
