Q1->
  class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size()-1;i++){
            int r1=nums[i]%2;
            int count=0;
            for(int j=i+1;j<nums.size();j++){

                int r2=nums[j]%2;

                if(r1!=r2) count++;
                
            }

            ans.push_back(count);
        }

        ans.push_back(0);

        return ans;

        
    }
};

Q2->
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
    }
    int sumOfPrimesInRange(int n) {

        string temp=to_string(n);

        reverse(temp.begin(),temp.end());

        int rev=stoi(temp);


        int st=min(rev,n);

        int end=max(rev,n);

        long long ans=0;

        int curr=st;

        while(curr<=end){

            if(isprime(curr)){
                ans+=curr;
            }
            curr++;
        }

        return ans;
        
    }
};
