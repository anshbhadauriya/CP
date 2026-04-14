class Solution {
public:
vector<string>ans;
int n;

void solve(int i,string curr,string &s){
    

    if(i==s.size()){

        if(curr.back()=='.') curr.pop_back();

        int dots=0;

        if(curr.front()=='.') return;

        string temp;

        for(int j=0;j<curr.size();j++){
          

            if(curr[j]=='.') dots++;

            if(curr[j]=='.'){

             

                if(temp.size()>=2 and temp.front()=='0'){

                    return;
                    
                }

                temp.clear();
            }
            else{
            temp.push_back(curr[j]);
            }
            
        }
        if(temp.size()>=2 && temp.front()=='0'){
               return;
               }

        if(dots==3) ans.push_back(curr);

        

        return;
    }

    
    solve(i+1,curr+s[i]+'.',s);

    // curr.push_back('.');

    if(i+2<=n)
    solve(i+2,curr+s.substr(i,2)+'.',s);

    if(i+3<=n and stoi(s.substr(i,3))<=255)
    solve(i+3,curr+s.substr(i,3)+'.',s);
    

    
    
    }


    vector<string> restoreIpAddresses(string s) {
        /*
        3 dots  4 parts
        each<=255
        no leading zeros
        no alpha
        TAKE DOT
        */

        string curr="";
        n=s.size();

         solve(0,curr,s);

         vector<string>res;

         
         return ans;


    }
};
