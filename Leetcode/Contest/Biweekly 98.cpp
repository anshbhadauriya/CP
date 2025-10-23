Q1->
class Solution {
public:
    int minMaxDifference(int num) {
        vector<int>temp1;
        while(num>0){
            temp1.push_back(num%10);
            num=num/10;
        }
        reverse(temp1.begin(),temp1.end());

        vector<int>maximum(temp1.begin(),temp1.end());
        int val;
        for(int i=0;i<maximum.size();i++){
            if(maximum[i]!=9){
                val=maximum[i];
                break;
            }
        }
        int sum=0;
        for(int i=0;i<maximum.size();i++){
            if(maximum[i]==val){
                maximum[i]=9;
            }
            sum=sum*10+maximum[i];
        }

        vector<int>minimum(temp1.begin(),temp1.end());
        int val1=minimum[0];
        int sum1=0;
        for(int i=0;i<minimum.size();i++){
           if(minimum[i]==val1){
               minimum[i]=0;
             
           }
              sum1=sum1*10+minimum[i];
        }
        return sum-sum1;
        
        
    }
};

Q2->

class Solution {
public:
        int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int case1=nums.back()-nums[2];
        int case2=nums[nums.size()-3]-nums[0];
        int case3=nums[nums.size()-2]-nums[1];
        return min({case1,case2,case3});
    
    }
};
