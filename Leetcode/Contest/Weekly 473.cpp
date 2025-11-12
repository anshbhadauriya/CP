Q1-> class Solution {
public:
    long long removeZeros(long long n) {
        vector<long long>temp;
        while(n>0){
            int x=n%10;
            if(x!=0){
                temp.push_back(x);
            }
            n=n/10;
        }
        reverse(temp.begin(),temp.end());
        long long sum=0;
        for(int i=0;i<temp.size();i++){
            sum=sum*10+temp[i];
        }
        return sum;
        
    }
};

Q2->
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int size=nums.size()/2;
        for(int i=0;i<size;i++){
            sum=sum-nums[i]*nums[i];
        }
        for(int i=size;i<nums.size();i++){
            sum=sum+nums[i]*nums[i];
        }
        return sum;
       
    }
Q3->
class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n=capacity.size();
        vector<long long int>prefix(n+1,0);

        for(int i=1;i<=n;i++) {
            prefix[i]=prefix[i-1]+capacity[i-1];
        }

        map<pair<long long int, long long int>, long long int> mp;
        long long int ans=0;

        for (int r = 3; r<=n;r++) {
            long long int tar=prefix[r]-2LL * capacity[r-1];
            mp[{prefix[r - 2], capacity[r - 3]}]++;
            ans += mp[{tar, capacity[r - 1]}];
        }

        return ans;
    }
};

};
