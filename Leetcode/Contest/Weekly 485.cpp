class Solution {
public:
    int vowelConsonantScore(string s) {
        unordered_set<char>st{'a','e','i','o','u'};
        int v=0,c=0;

        for(int i=0;i<s.size();i++){
            if(!isalpha(s[i])){
                continue;
            }
            if(st.count(s[i])){
                v++;
            }
            else{
                c++;
            }
        }
        if(c>0){
            return floor(v/c);
        }
        return 0;
    }
};
