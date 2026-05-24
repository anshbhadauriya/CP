Q1->
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        

        vector<int>ans;

        for(auto x:nums){

            if(mp[x]<k){
                ans.push_back(x);
            mp[x]++;
            }
        }

        return ans;
    }
};

Q2->
class Solution {
public:
    int passwordStrength(string password) {

        unordered_set<char>lc,uc,digit,sc;

        for(auto x:password){

            if(islower(x)){
                lc.insert(x);
            }
            else if(isupper(x)){
                uc.insert(x);
            }
            else if(isdigit(x)){
                digit.insert(x);
            }
            else{
                sc.insert(x);
            }
        }

        return lc.size()+(2*uc.size())+(3*digit.size())+(5*sc.size());
        
    }
};

Q3->

class Solution {
public:
    int minOperations(vector<int>& nums) {

        /*

        yaa too pura array reverse kro

        left wale ele ko right me krdo (left rotation)


        sort in increasing order 

        1,3,2,0

        0,1,3,2

        1,3,2,0

        yha 3 problematic hai

        bcs 3 is greater than its left and righ,,lekin last ele too aissa hi hoga

        number 0 to n-1 ki range me hai

        impossible if left rotation aur reverse se possible na ho

        
        
        */

        int n=nums.size();
        int drops=0;

        //sbse pehle starting idx find kro

        int st_idx=-1;

        for(int i=0;i<n;i++){

            if(nums[i]==0){
                st_idx=i;
                break;
            }
        }

        cout<<"starting idx is "<<st_idx<<endl;

        //abh check kro ki kya ham rotations krke isko sort kr skte hai

        bool forward_possible=true;


        

        for(int i=0;i<n;i++){  //sare ele idx ke barabar hone chaiye

            if(nums[(i+st_idx)%n]!=i){
                forward_possible=false;
                break;
            }
        }

        bool backward_possible=true;

        for(int i=0;i<n;i++){
            if(nums[(st_idx-i+n)%n]!=i){
                backward_possible=false;
                break;
            }
        }

        //agr dono se possible na ho to return -1

        if(!forward_possible and !backward_possible) return -1;

        int minimum=INT_MAX;

        if(forward_possible){

            minimum=min(minimum,st_idx);

            int right_shift_cost=2+(n-st_idx)%n;

            minimum=min(minimum,right_shift_cost);
        }

        if(backward_possible){

            //jab tk 0 end me na aaaje tab tk shift kro fir reverse 

            int shift_to_last=1+(st_idx+1)%n;

            minimum=min(minimum,shift_to_last);

            int reverse_shift=n-st_idx;

            minimum=min(minimum,reverse_shift);
            
        }

        return minimum;
        
    }
};
