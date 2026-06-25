Optimal->
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;

        vector<vector<string>>result;

       for(auto &x:strs){

        vector<int>freq(26,0);

        for(auto i:x) freq[i-'a']++;

        string key="";

        for(int i=0;i<26;i++){
            if(freq[i]>0) key+=to_string(i)+"->"+to_string(freq[i])+"#";

         
        }

          

        mp[key].push_back(x);
       }

       for(auto &x:mp) result.push_back(x.second);
       
       return result;
    }
};

/*
here instead of sorting we generate unique key for each anagram so we dont need to sort
just match key

key is idx->freq

so now tc->O(n.m)
Sc-> O(n.m)
*/

Simple->
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;

        for(auto x:strs){

            string copy=x;
            sort(copy.begin(),copy.end());

            mp[copy].push_back(x);
        }

        vector<vector<string>>ans;

        for(auto &x:mp) ans.push_back(x.second);

        return ans;
    }
};

/*
TC-> let m be length of each word so h ar word ko sort kr rhe ham so O(n)*O(m log(m))
copy bana rhe har word ka O(n)*O(m)
so its prolly O(n) * O(m log(m))

Sc-> 
*/
