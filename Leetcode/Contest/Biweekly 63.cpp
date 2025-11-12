Q1->

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int count=0;
        for(int i=0;i<seats.size();i++){
            count=count+abs(students[i]-seats[i]);
        }
        return count;
    }
};


Q2->
class Solution {
public:
    bool winnerOfGame(string colors) {
       int cons_a=1,cons_b=1,alice_turn=0,bob_turn=0;
        for(int i=1;i<colors.size();i++){

            if(colors[i]==colors[i-1]){
                if(colors[i]=='A'){
                    cons_a+=1;
                }
                else{
                    cons_b+=1;
                }
            }
            else{

                if(cons_a>=3){
                    alice_turn+=cons_a-2;
                    
                }
                if(cons_b>=3){
                    bob_turn+=cons_b-2;
                    
                }
                cons_a=1;
                cons_b=1;
            }
              
            
            
        }
        if(cons_a>=3){
                    alice_turn+=cons_a-2;
                    
                }
                if(cons_b>=3){
                    bob_turn+=cons_b-2;
                    
                }
        if(bob_turn>=alice_turn){
            return false;
        }
        return true;
        
        
    }
};

