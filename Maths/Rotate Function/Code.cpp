class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {

        int n=nums.size();
        vector<int>dp(n);

        int sum=accumulate(nums.begin(),nums.end(),0);

        int temp=0;

        

        for(int i=0;i<n;i++){
            temp+=(i*nums[i]);
        }

        cout<<"temp-> "<<temp<<endl;

        dp[0]=temp;

        int maximum=dp.front();

        for(int i=1;i<n;i++){
            dp[i]=dp[i-1]+sum-n*nums[n-i];

            maximum=max(maximum,dp[i]);

            cout<<dp[i]<<" ";
        }

       

        return maximum;
        
    }
};