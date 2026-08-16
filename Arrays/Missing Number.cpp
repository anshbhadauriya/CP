class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n=nums.size();
        
        int total=n*(n+1)/2;

        for(auto x:nums) total-=x;

        return total;
        
    }
};

/*
sare idx ^ sare ele = 0
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n=nums.size();

        int xorr=n;

        for(int i=0;i<n;i++){
            xorr=xorr^i;
            xorr=xorr^nums[i];
        }

        return xorr;
        
    }
};
