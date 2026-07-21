/*
brute force is simple
s1 ko sort kro
s2 se sari s1 size ki substring ko sort krke s1 se match kro 
if they are equal so return true

there is a simple technique also
use minimum window substring pattern here and check that min window size is == s1 size
if it is so return true 
else return false


just use MINIMUM WINDOW SUBSTRING
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        vector<int>mp(26,0);

        for(auto x:s1) mp[x-'a']++;

        int l=0,h=0,count=0,min_size=INT_MAX;

        while(h<s2.size()){

            if(mp[s2[h]-'a']>0) count++;

            mp[s2[h]-'a']--;

            while(count==s1.size()){

                int st_idx=l;
                int curr_size=h-l+1;

                if(curr_size<min_size){
                    min_size=curr_size;

                }

                mp[s2[l]-'a']++;

                if(mp[s2[l]-'a']>0) count--;

                l++;
            }

            h++;

        }

        if(min_size==s1.size()) return true;

        return false;
        
    }
};
/*
TC-> O(n+m)
SC-> O(1)
*/
