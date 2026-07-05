class Solution {
public:

//first digit jiski large hai usse aage kro

static bool cmp(string &s1,string &s2){

    if(s1+s2>s2+s1) return true;
    return false;
}
    string largestNumber(vector<int>& nums) {

        vector<string>temp;

        for(auto &x:nums) temp.push_back(to_string(x));

        sort(temp.begin(),temp.end(),cmp);

        string ans="";

        for(auto &x:temp) ans+=x;

        while(ans.size()>1 and ans.front()=='0') ans.erase(ans.begin());

        return ans;
        
    }
};
/*
// Time Complexity: O(n log n * k)
// n = number of elements
// k = average number of digits (comparison involves concatenation)

// Space Complexity: O(n * k)
*/
