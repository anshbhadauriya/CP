/*
20 50 100 200 500

big notes will be given priority

*/
class ATM {
public:

vector<int>temp={0,0,0,0,0};

    ATM() {
        
    }
    
    void deposit(vector<int> banknotesCount) {

        for(int i=0;i<banknotesCount.size();i++){

            temp[i]+=banknotesCount[i];
        }
        
    }
    
    vector<int> withdraw(int amount) {

    vector<int>ans={0,0,0,0,0};

        for(int i=4;i>=0;i--){

            int to_remove=0;

            if(i==4) to_remove=500;
            else if(i==3) to_remove=200;
            else if(i==2) to_remove=100;
            else if(i==1) to_remove=50;
            else to_remove=20;

            int can_take=min(temp[i],amount/to_remove);  //yaa too kam notes available hoge ya to kam notes required hoge too complete the amount
            //so basically can_take is the number of notes we can take

            temp[i]-=can_take;
            amount-=can_take*to_remove;
            ans[i]=can_take;


            if(amount==0) return ans;

        }

        for(int i=0;i<5;i++){
            temp[i]+=ans[i];
        }

        return {-1};


        
    }
};

