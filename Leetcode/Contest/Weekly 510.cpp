Q1->
class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {

    

        string hour1=startTime.substr(0,2);
        string hour2=endTime.substr(0,2);

        string min1=startTime.substr(3,2);
        string min2=endTime.substr(3,2);

        string sec1=startTime.substr(6,2);
        string sec2=endTime.substr(6,2);

        int ans=0;

        ans+=((stoi(hour2)-stoi(hour1))*60)*60;

        ans+=(stoi(min2)-stoi(min1))*60;

        ans+=stoi(sec2)-stoi(sec1);

        return ans;
    }
};

Q2->

/*
k unit of resources

agr kbhi k< nums[i] si increase k by k
*/
class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {

        int resource=k;

        int cost=0,operations=1;

        int mod=1e9+7;
        
        for(int i=0;i<nums.size();i++){

            if(resource<nums[i]){

                long long need=nums[i]-resource;
                long long op=(need+k-1)/k;
                long long op_m=op%mod;

                // long long first=operations;

                // long long last=(operations+op_m-1)%mod;

            long long sum=(op_m*(2LL*operations+op_m-1)/2)%mod;

          //      sum=sum*

                cost=(cost+sum)%mod;

                operations=(operations+op_m)%mod;

                resource+=op*k;
               
            }

            resource-=nums[i];
        }

        return cost;
        
    }
};
