Q1->

class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum=0;

        for(int x=0;x<=200;x++){

            if(abs(n-x)<=k and (n&x)==0) sum+=x;
        }

        return sum;
        
    }
};

Q2->

  class Solution {
public:

    void solve(int i,int n,int k,int cost,bool prev,string &s,vector<string>&ans){

        if(i==n){
 if(cost>k) return;
           
            ans.push_back(s);
            return;
        }

        s.push_back('0');

        solve(i+1,n,k,cost,false,s,ans);

        s.pop_back();

        //agr prev nhi lia aur cost valid hai tabhi 1 lo

        if(!prev ){
            s.push_back('1');
            solve(i+1,n,k,cost+i,true,s,ans);
            s.pop_back();
        }

        
    }
    vector<string> generateValidStrings(int n, int k) {
        /*

        valid if
        
        no 2 consecutive 1's
        cost<=k

        sare possible generate krdo
        
        */

        vector<string>ans;

        string s;

         solve(0,n,k,0,false,s,ans);

        return ans;

        
        
    }
};
