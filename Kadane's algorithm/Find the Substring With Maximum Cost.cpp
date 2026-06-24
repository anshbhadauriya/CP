/*
String s
String chars -> distincts chars
vals

cost of subtring = sum of all chars in substring

empty string cost = 0

agr koi ele chars me nhi so uski cost uski ele-'a' + 1

if ele is in char then its value is vals[i]

pehle chars ko vals se map krdo


*/

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {

        vector<int>mp(26,1001);  //1001 is indicating that freq is 0

        for(int i=0;i<chars.size();i++){
            mp[chars[i]-'a']=vals[i];
        }

        //prolly use kadane's algo

        //har idx pr check kro ki yha se new subarray banae yaa prev me hi add krde

        int maximum=-1001,curr_sum=-1001;
        for(int i=0;i<s.size();i++){

            int val;

            if(mp[s[i]-'a']!=1001)  val=mp[s[i]-'a'];
        
            else val=(s[i]-'a')+1;

            curr_sum=max(curr_sum+val,val);  //new subarray or extend previous
            maximum=max(maximum,curr_sum);
        }

        return (maximum<0)?0:maximum;
        
    }
};
