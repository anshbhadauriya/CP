/*
pehle check 2 char combine is in hashmap or not if yess then use that
if no so use single one 

add values

is it that simple?

worked! now optimize

we can use char instead of string in mp and reduce values

and the key observation is if smaller value comes befor larger value then subtract

suppose if XL so here X is 10 and L is 50, so here X comes before L so we have to subtract L-X and add that value so XL value becomes 40

approach 1 feels more intutive btw 

tc is O(n) and sc is O(1)

*/
class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char,int> mp = {
    {'I',1},
    {'V',5},
    {'X',10},
    {'L',50},
    {'C',100},
    {'D',500},
    {'M',1000}
};

    int answer=0,n=s.size();

    for(int i=0;i<n;i++){
        if(i+1<n and mp[s[i]]<mp[s[i+1]]){
            answer+=mp[s[i+1]]-mp[s[i]];  //instead u can also do like answer-=mp[si] when small is before large and then skip this line-> i++ both are kinda same 
            i++;
        }
        else answer+=mp[s[i]];
    }

    return answer;
    }
};
