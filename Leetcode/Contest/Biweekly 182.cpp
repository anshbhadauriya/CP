Q1->

  class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int counter=0;

        unordered_set<string>st{"0","1","2","3","4","6"};

        int score=0,total_score=0;

        for(int i=0;i<events.size();i++){

            

            if(st.count(events[i])){
                total_score+=stoi(events[i]);
            }

            if(events[i]=="W"){
                counter+=1;
            }
            if(events[i]=="WD"){
                total_score+=1;
            }
            if(events[i]=="NB"){
                total_score+=1;
            }
            if(counter==10) break;
            
        }

        return {total_score,counter};
    }
};

Q2->

  class Solution {
public:
    int minFlips(string s) {

        /*

        yaa too all 0

        yaa too all 1

        yaa too 10001

        yaa too 001000

        */

        int n=s.size();

        if(n<=2) return 0;

        int one=0,zero=0;

        int mid_zero=0;

        for(int i=0;i<n;i++){

            if(s[i]=='1') one++;
            else zero++;


            if(i!=0 and i!=n-1 and s[i]=='0') mid_zero++;
            

        }



        int ans=min(one,zero);  //sbko same bana dia

        ans = min(ans, max(0, one - 1));

        cout<<ans;

        int count=0;

        if(s.front()!='1'){
            count+=1;
        }
        if(s.back()!='1'){
            count+=1;
        }

        count+=(s.size()-2)-mid_zero;

        return min(ans,count);

        
    }
};

