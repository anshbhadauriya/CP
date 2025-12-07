Q1->

  class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int,int>>result;
        for(int i=0;i<nums.size();i++){
            string binary;
            int num=nums[i];
            while(num>0){
                int r=num%2;
                binary=to_string(r)+binary;
                num=num/2;
            }
            reverse(binary.begin(),binary.end());
            int xx=0;
            for(char c:binary){
                xx=xx*2+(c-'0');
            }
           
            result.push_back({xx,nums[i]});
        }
        sort(result.begin(),result.end());
        vector<int>ans;
        for(int i=0;i<result.size();i++){
            ans.push_back(result[i].second);
        }
        return ans;
        
        
    }


Q2->

class Solution {
public:
    bool isprime(int num){
        if(num<=1){
            return false;
        }
        if(num==2){
            return true;
        }
        if(num%2==0){
            return false;
        }
        for(int i=3;i*i<=num;i=i+2){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
    int largestPrime(int n) {
        int count=0,last=0;
        for(int i=2;i<=n;i++){
            if(isprime(i)){
                count=count+i;
                if(count>n){
                    break;
                }
                cout<<count<<" ";
                if(isprime(count)){
                    last=count;
                }
            }
        }

        return last;
        
    }
};
};
