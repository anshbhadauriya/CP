Q1->
  class Solution {
public:
    int countCommas(int n) {
        string curr=to_string(n);
        if(n<1000) return 0;

        if(n<10000){
            int ans=n-1000;
            return ans+1;
        }
        int ans=n-1000;

        return ans+1;
        
    }
};

Q2->
  class Solution {
public:
    long long countCommas(long long n) {

        string curr=to_string(n);
        long long count=0;

        long long last=1000;

        while(n>=last){
            count+=(n-last+1);
            last*=1000;
        }

        return count;

        
        
    }
};
