/*
n cars jo ki 0 miles se dur hai
aur kitna dur hai vo given hai

traveling to reach the target 

so basically kitni cars sth aaegi yeh batana hai


*/
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n=position.size();

        vector<double>time(n);

        vector<pair<int,int>>info;  //pos,speed


        for(int i=0;i<n;i++){
            info.push_back({position[i],speed[i]});
        }

        sort(info.begin(),info.end());

        for(int i=0;i<n;i++){
            int pos=info[i].first;
            int spe=info[i].second;
            int dist=target-pos;

            time[i]=(1.0*dist)/(1.0*spe);

            // cout<<time[i]<<" ";
        }
        // cout<<endl;

        //now nge will combine and form fleet

        stack<double>st;

        // sort(time.begin(),time.end());

        for(int i=n-1;i>=0;i--){

            if(st.empty() or time[i]>st.top()) st.push(time[i]); //agr curr time chota hai aage wale se too chota wala aage wale ke sth hi mix hojaega
        }

        return st.size();



        
    }
};
