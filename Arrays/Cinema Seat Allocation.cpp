/*
n x n rows hai
reserved given h

so agr 2 se hai too first seq nhi bnega
4 reserve hai too second seq nhi bnega
6 reserve hai too third

lekin agr 4,5 me se koi reserve hai too too seq 1,2 possible nhi h
agr 6,7 me koi reserve hai too seq 2,3 nhi bnega

agr kisi row me ek bhi issue nhi h too count+=2
*/
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        // vector<vector<int>>cinema(n+1,vector<int>(3,1));

        unordered_map<int,unordered_set<char>>mp;

        //first wali row ko skip krdena baad me

        for(auto x:reservedSeats){

            int row=x[0];
            int seat=x[1];

            /*
            agr 2 ya 3 hai seat too first ele ko 0 krdo
            agr 4 5 hai seat too first aur second ele ko 0 krdo
            agr 6 7 hai seat too second aur third ele ko  
            */

            // auto &curr=cinema[row];

            if(seat==2 or seat==3){

                mp[row].insert('a');
            }
            else if(seat==4 or seat==5){
                mp[row].insert('a');
                mp[row].insert('b');
            }
            else if(seat==6 or seat==7){

                mp[row].insert('b');
                mp[row].insert('c');

              
            }
            else if(seat==8 or seat==9){

                mp[row].insert('c');
            }
        }

        int count=2*n; //har row ke paas se 2 mil skte h


        //sare valid count krne se accha sare invalid count krlo

        for(auto x:mp){

            auto &st=x.second;


            if(st.size()==2 or st.size()==1) count-=1;

            else if(st.size()==3) count-=2;

        }

        return count;


    }
};
