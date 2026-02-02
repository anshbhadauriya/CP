class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int l=0,h=0,maximum=INT_MIN,max_freq=0;
        while(h<s.size()){
            mp[s[h]]++;
             max_freq=max(max_freq,mp[s[h]]);
            int length=h-l+1;
            int operations=length-max_freq;
            while(operations>k and l<=h){    //window size - max frequency of a character
                mp[s[l]]--;
                l++;
                length=h-l+1;
                operations=length-max_freq;

            }
            maximum=max(maximum,h-l+1);
            h++;
        }
        return maximum;
    }
};
