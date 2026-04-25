Q1->
  class Solution {
public:
    bool validDigit(int n, int x) {

        string str=to_string(n);

        if(str.front()-'0'==x) return false;

        for(auto a:str){
            if(a-'0'==x) return true;
        }

        return false;
        
    }
};

Q2->

  class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {

        long long sum1=0,sum2=0,idx=1;

        for(int i=0;i<nums.size()-1;i++){
            sum1+=nums[i];
            cout<<nums[i]<<" ";
            if(nums[i+1]<nums[i]){
                idx=i+1;
                break;
            }
        }

        cout<<endl;

        for(int i=idx-1;i<nums.size();i++){
            sum2+=nums[i];
            cout<<nums[i]<<" ";
        }

        cout<<endl;

        if(sum1>sum2) return 0;

        if(sum1==sum2) return -1;

        return 1;

        
        
    }
};
