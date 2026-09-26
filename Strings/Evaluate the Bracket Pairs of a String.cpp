/*
straightforward
*/
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;

        for(auto &x:knowledge) mp[x[0]]=x[1];

        int st=-1;
        bool open=false;
        string ans="";
    
       for(int i=0;i<s.size();i++){

        if(s[i]=='('){
            open=true;
            st=i+1;
            continue;
        }

        if(s[i]==')'){

            open=false;

            string temp=s.substr(st,(i-1)-(st)+1);

            if(mp.count(temp)) ans+=mp[temp];
            else ans+='?';

            st=-1;
            continue;
        }
        
        if(!open) ans+=s[i];
       }

       return ans;
        
    }
};
