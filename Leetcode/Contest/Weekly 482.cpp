Q1->

  class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        vector<long long>prefix(nums.size(),0),suffix(nums.size());
        long long pref=0;
        for(int i=0;i<nums.size();i++){
            pref+=nums[i];
            prefix[i]=pref;
        }

        suffix[nums.size()-1]=nums[nums.size()-1];
        long long minimum=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            if(minimum>nums[i]){
                minimum=nums[i];
            }
            suffix[i]=minimum;
        }
        long long maximum=LLONG_MIN;
        for(int i=0;i<nums.size()-1;i++){
            if(maximum<prefix[i]-suffix[i+1]){
                maximum=prefix[i]-suffix[i+1];
            }
            
        }
        return maximum;

    }
};

Q2->

  class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1=cost1;
        long long c2=cost2;
        long long cb=costBoth;
        long long n1=need1;
        long long n2=need2;
        long long res1=(n1*c1)+(n2*c2);

        long long aa=min(n1,n2);

        long long p1=aa*cb;
        long long p2=(n1-aa)*c1;
        long long p3=(n2-aa)*c2;

        long long res2=p1+p2+p3;
        long long res3=max(n1,n2)*cb;
        return min({res1,res2,res3});
        
    }
};

Q3->

  class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k%2==0 or k%5==0){
            return -1;
        }
        string str;
        long long one=0,num=0,i=0;
        while(i<k){
             num=(num*10+1)%k;
             cout<<num<<" ";
            if(num==0){
                return i+1;
            }
            i++;
            
        }
        return -1;
    }
};
