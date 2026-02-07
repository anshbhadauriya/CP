Appraoch 1->

  class Solution {
public:
    int minimumDeletions(string s) {
        string st;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push_back(s[i]);
                continue;
            }
            if(st.back()=='b' and s[i]=='a'){  //agr kabhi bhi b-a pair ban rha too count++ and skip curr element
                st.pop_back();
                count++; 
                continue;  
            }
            st.push_back(s[i]);
        }
        return count;
        
    }
};

Approach 2->

  class Solution {
public:
    int minimumDeletions(string s) {

        //har index ke lie count kro ki b kitne pehle aachuke hai aur a kitne aane wale hai soo if you delete before b and after a so string will become balanced so you need to check which index after_a[i]+before_b[i] will be minimum kyuki whi minimum deletion honge
        int n=s.size();
        vector<int>before_b(n,0),after_a(n,0);

        int count_b=0;

        for(int i=0;i<n;i++){
            before_b[i]=count_b;
            if(s[i]=='b'){
                count_b++;
            }
        }

        int count_a=0;

        for(int i=n-1;i>=0;i--){
            after_a[i]=count_a;

            if(s[i]=='a'){
                count_a++;
            }
        }

        int minimum=INT_MAX;

        for(int i=0;i<n;i++){
            minimum=min(minimum,after_a[i]+before_b[i]);
        }
        return minimum;
    }
};


Approach 3->

  class Solution {
public:
    int minimumDeletions(string s) {
        //same as previous approach just removed vectors to save space
        int count_a=0,count_b=0;
        for(auto x:s){   //pehle sare a count krlo
         if(x=='a')
          count_a++;
        }

        int minimum=INT_MAX;

        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                count_a-=1;
            }
            minimum=min(minimum,count_a+count_b);
            if(s[i]=='b'){
                count_b++;
            }
        }

        return minimum;
        
    }
};
