class Solution {
public:
    int numberOfSubstrings(string s) {

        int l=0,h=0,count=0;

        unordered_map<char,int>mp;

        while(h<s.size()){

            mp[s[h]]++;

            while(mp.size()>2 and l<=h){

                mp[s[l]]--;
                count+=s.size()-h;

                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }

            
            
            h++;
        }

        return count;
        
    }
};
