class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(auto x:t){
            mp[t]++;
        }
        int l=0,h=0;
        while(h<s.size()){

           if(mp[nums[h]]>0){
            ++count;
           }
           mp[nums[h]]--;
           while(count==t.size()){
                if(h-l+1<minimum) {
                    minimum=h-l+1;
                    start_idx=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0){
                    count--;
                }
                l++;
            }
            h++;
           }

            
        }
        if(start_idx==-1){
            return "";
        }
        return s.substr(start_idx,minimum);
    }
};