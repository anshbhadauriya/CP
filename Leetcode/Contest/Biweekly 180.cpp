class Solution {
public:
    string trafficSignal(int timer) {

        if(timer==0){
            return "Green";
        }
        if(timer==30){
            return "Orange";
        }

        if(timer>30 and timer<=90){
            return "Red";
        }

        return "Invalid";
    }
};


class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            string temp=to_string(nums[i]);

            for(int j=0;j<temp.size();j++){
                if(temp[j]==digit+'0'){
                    count++;
                }
            }
        }
        return count;
    }
};

class Solution {
public:
    bool isprime(int n){
        if(n<=1) return false;
        if(n<=3) return true;

        if(n%2==0 or n%3==0) return false;

        for(int i=5;i*i<=n;i+=6){
            if(n%i==0 or n%(i+2)==0) return false;
        }

        return true;
        //i hope u know using templates is not cheating :)
    }
    int minOperations(vector<int>& nums) {
        //alternating prime if 
        //even idx are prime
        //odd idx are non prime
        //u can increment by 1

        long long cost=0;

        for(int i=0;i<nums.size();i++){
            int curr=nums[i];
            if(i%2==0){
                while(!isprime(curr)){
                    cost++;
                    curr++;
                }
                //find next prime number 

                
            }
            else if(i%2!=0){

                while(isprime(curr)){
                    cost++;
                    curr++;
                }
                
            }
        }

        return cost;

        
    }
};
