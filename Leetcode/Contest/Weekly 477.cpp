Q1->

  class Solution {
public:
    long long sumAndMultiply(int n) {
        long long count=0,sum=0;
        string temp=to_string(n);
        for(int i=0;i<temp.size();i++){
            int curr=temp[i]-'0';
            if(curr!=0){
                count=count+curr;
                sum=sum*10+curr;
            }
        }
        return sum*count;
    }
};

Q2->

  class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        map<pair<int,int>,int>mp;

        mp[{0,0}]=-1;
        int xorr=0,odd=0,even=0,maximum=0;

        for(int i=0;i<nums.size();i++){
            xorr=xorr^nums[i];
            if(nums[i]%2==0){
                even++;
            }
            else{
                odd++;
            }
            int diff=even-odd;
            pair<int,int>key={xorr,diff};

            if(mp.find(key)!=mp.end()){
                maximum=max(maximum,i-mp[key]);
            }
            else{
                mp[key]=i;
            }
        }
        return maximum;
    }
};
