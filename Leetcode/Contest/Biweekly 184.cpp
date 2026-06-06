Q1->

class Solution {
public:
    bool consecutiveSetBits(int n) {

        string binary="";

        while(n>0){

            binary=to_string(n%2)+binary;
            n=n/2;
        }

        int count=0;
        int size=binary.size();

        for(int i=0;i<size;i++){
            if(binary[i]=='1' and binary[i+1]=='1') count++;
        }

        if(count==1) return true;

        return false;
        
    }
};

Q2->

class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {

        /*

        0 to n-1 bulbs

        brightness 

        intervals[i] kab se kab tk light jlegi

        either on or off 

        agr koi bulb on hai too vo apni aur adj ki position ko illuminate krega

        har bulb take 1 energy 

        return min total energy req

        naam is BS??

        1 bulb = 3 idx cover krega

        so energy+=1
        
        
        */
        long long light;
        if(brightness>=3){
         light=brightness/3;

        if(brightness%3!=0 and brightness>3) light++;
        }
        else light=1;

        long long energy=0;

        sort(intervals.begin(),intervals.end());

        vector<vector<int>>temp;

        for(auto x:intervals){

            if(temp.empty()){
                temp.push_back(x);
            continue;
            }

            int n=temp.size();

            int l2=x[0],h2=x[1];
            int l1=temp.back()[0];
            int h1=temp.back()[1];

            if(l1>h2 or h1<l2){ //not mergin
                temp.push_back(x);
            }

            else{
                int new_l=min(l1,l2);
                int new_h=max(h1,h2);

                temp[n-1][0]=new_l;

                temp[n-1][1]=new_h;
            }
        }

    for(auto x:temp){

    int a=x[0],b=x[1];
    energy+=b-a+1;
    }

        return light*energy;

        
        
    }
};

Q3->

class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {

        /*

        binary string hai

        s[i]==1 mtlb it contains token

        s[i]==0 no token

        operations:

        

        token lo aur usse i-1 pr rkh do i>0 hona chaiye aur vo token pehli bar hi change kr skte ho position

        so basically hme tokens aisse idx me lana hai jaha value large ho

        har har token ek bar hi positon change kr skte

        
        */

        int n=nums.size();

        long long ans=0,prev=-1;

        //prev no 0 find kro

            if(s.front()=='0') prev=0;

        for(int i=1;i<n;i++){
            if(s[i]=='1' and s[i-1]=='0' and nums[i-1]>nums[i]){
            s[i]='0';
            s[i-1]='1';
            }

            if(s[i]=='0' and prev==-1){
                prev=i;
                continue;
            }
            if(s[i]=='1' and prev!=-1){
                
                if(nums[prev]>nums[i]){
                    s[prev]='1';
                    s[i]='0';
                }
            }

            if(s[i]=='0') prev=i;
        }

       for(int i=0;i<n;i++){
           if(s[i]=='1') ans+=nums[i];
       }

        return ans;
        
    }
};
