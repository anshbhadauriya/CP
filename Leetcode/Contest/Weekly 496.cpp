Q1->
class Solution {
public:
    int mirrorFrequency(string s) {

        unordered_map<char,int>mp;
        for(auto x:s) mp[x]++;
        int sum=0;

        unordered_set<char>st;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(st.count(c)) continue;

            int c_freq=mp[c];
            char m;
            if(isalpha(c))
             m='z'-(c-'a');

             else m='9'-(c-'0');

             int m_freq=mp[m];

             sum+=abs(c_freq-m_freq);

             st.insert(m);
             st.insert(c);

        }
        return sum;
        
    }
};
Q2->
class Solution {
public:
    vector<int> findGoodIntegers(int n) {

        //a and b +ve 

        //curr = a+b

        unordered_map<int,int>mp;

        for(int a=1;a<=n;a++){
            long long a_cube=a*a*a;

            if(a_cube>n) break;

            for(int b=a;b<=n;b++){
                long long val=a_cube+(b*b*b);

                if(val>n) break;

                mp[val]++;
            }
        }
vector<int>ans;
        for(auto x:mp){
            if(x.second>=2) ans.push_back(x.first);
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};
