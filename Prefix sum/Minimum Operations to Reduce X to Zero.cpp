/*
so we have choices in each state
either take ele from front or back
dp can work but it will give tle bcs 10 pow 5
dp first- got tle

1 2 6 8 11
11 10 9 5 3  

doneee

not optimal but good enough
*/
class Solution {
public:

    int minOperations(vector<int>& nums, int x) {
       int n=nums.size();

       unordered_map<int,int>mpPrefix,mpSuffix;

       int s1=0,s2=0;

       for(int i=0;i<nums.size();i++){
        s1+=nums[i];
        mpPrefix[s1]=i+1;
       }

       for(int i=n-1;i>=0;i--){
        s2+=nums[i];
        mpSuffix[s2]=n-i;
        //cout<<n-i<<" ";
       }

       int minimum=INT_MAX;

       if(mpPrefix.count(x)) minimum=min(minimum,mpPrefix[x]); 
       if(mpSuffix.count(x)) minimum=min(minimum,mpSuffix[x]);

       int sum=0;

       for(int i=0;i<n;i++){

        sum+=nums[i];

        if(mpSuffix.count(x-sum) and n-(i+1)>=mpSuffix[x-sum]){
            minimum=min(minimum,i+1+mpSuffix[x-sum]);
        }
       } 

       return minimum==INT_MAX?-1:minimum;
    }
};
