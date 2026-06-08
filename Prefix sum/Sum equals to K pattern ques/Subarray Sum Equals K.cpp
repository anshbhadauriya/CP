class Solution {
public:

/*

yaha pr <=k - <k == k wali trick nhi work kregi kyuki -ve numbers bhi ha.. agr sirf +ve numbers hote too vo bhi work krti 

TC and SC of curr appraoch O(n)
*/
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int>mp;

        int l=0,h=0,n=nums.size(),sum=0,ans=0;

        mp[0]=1;  //used in edge cases like nums=[1,-1] , k=0

        while(h<n){

            sum+=nums[h];

            if(mp.count(sum-k)){  //agr sum-k aaachuka hai mtlb let x so sum-x=k hojaega (like 2sum)

              ans+=mp[sum-k];

            }

            mp[sum]++;

            h++;


        }

        return ans;
        
    }
};