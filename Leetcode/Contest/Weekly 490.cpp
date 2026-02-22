Q1-> 
  class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        bool first=true,second=false;
        int first_sum=0,second_sum=0,count=0;
        for(int i=0;i<nums.size();i++){
            ++count;
            if(count%6==0) swap(first,second);
            if(nums[i]%2!=0){
                swap(first,second);
                
            }
            if(first){
                first_sum+=nums[i];
            }
            if(second){
                second_sum+=nums[i];
            }
            
        }
        return first_sum-second_sum;
    }
};

Q2->

  class Solution {
public:
int factorial(int x){
    int fact=1;
    for(int i=1;i<=x;i++){
        fact=fact*i;
    }
    return fact;
}
    bool isDigitorialPermutation(int n) {
        string temp=to_string(n);
        long long fact_sum=0;
        while(n>0){
            int rem=n%10;
            fact_sum+=factorial(rem);
            n=n/10;
        }
        string ans=to_string(fact_sum);

        sort(ans.begin(),ans.end());

        sort(temp.begin(),temp.end());

        return ans==temp;

        


    }
};

Q3->

  class Solution {
public:
    string maximumXor(string s, string t) {

        //0 ke samne 1 laao to get max result

        int one=0,zero=0;
        for(int i=0;i<t.size();i++){
            if(t[i]=='1') one++;
            else zero++;
        }

        string ans;

        for(int i=0;i<s.size();i++){

            if(s[i]=='0'){
                if(one){
                    ans.push_back('1');
                    one--;
                }
                else{ 
                    ans.push_back('0');
                zero--;
                    }
            }

            else{
                if(zero){
                    ans.push_back('1');
                    zero--;
                }
                else{
                    ans.push_back('0');
                    one--;
                }
                
            }
            
        }
        

        return ans;
    }
};
