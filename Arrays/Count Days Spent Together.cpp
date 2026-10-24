class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        vector<int>months={31,28,31,30,31,30,31,31,30,31,30,31};

        int startMonthOfAlice=stoi(arriveAlice.substr(0,2));
        int startDayOfAlice=stoi(arriveAlice.substr(3,2));
        int endMonthOfAlice=stoi(leaveAlice.substr(0,2));
        int endDayOfAlice=stoi(leaveAlice.substr(3,2));


        int startMonthOfBob=stoi(arriveBob.substr(0,2));
        int startDayOfBob=stoi(arriveBob.substr(3,2));
        int endMonthOfBob=stoi(leaveBob.substr(0,2));
        int endDayOfBob=stoi(leaveBob.substr(3,2));


        // cout<<startMonthOfAlice<<endl<<startDayOfAlice<<endl;



        vector<int>visited(1232,0);  //month,day

        int st=startMonthOfAlice*100+startDayOfAlice;
        int end=endMonthOfAlice*100+endDayOfAlice;

        //cout<<"start day of Alice "<<startDayOfAlice<<endl;
        // cout<<"start month of Alice "<<startMonthOfAlice<<endl;

        for(int curr=st;curr<=end;curr++){

            int curr_month=(curr/100)-1;

            int maxDay=months[curr_month];

            int currDay=curr%100;

            if(currDay>maxDay){  //skip
                curr=((curr/100)+1)*100;
                continue;
            }

            // cout<<"Alice "<<curr_month<<" "<<currDay<<endl;

            
            
            visited[curr]=1;

           // cout<<curr<<" ";

        }

        // cout<<endl;

        int st2=startMonthOfBob*100+startDayOfBob;
        int end2=endMonthOfBob*100+endDayOfBob;
        int count=0;

        // cout<<st2<<" "<<end2<<endl;

        for(int curr=st2;curr<=end2;curr++){

            //if(curr%100==0) continue;
            int curr_month=(curr/100)-1;

            int maxDay=months[curr_month];

            int currDay=curr%100;

            if(currDay>maxDay){
                curr=((curr/100)+1)*100;
                continue;
            }


            if(visited[curr]) count++;
        }




        return count;
        
        
        
    }
};
