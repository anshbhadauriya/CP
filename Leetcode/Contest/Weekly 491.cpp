class Solution {
public:
    string trimTrailingVowels(string s) {
        unordered_set<char>st{'a','e','i','o','u'};

        while(s.size()>0 and st.count(s.back())) s.pop_back();
        return s;
    }
};

class Solution {
public:
    int minCost(int n) {
        int cost=0;
        while(n>1){
            int a=n-1;
            int b=1;
            cost+=a*b;
            n=a;
        }
        return cost;
    }
};
