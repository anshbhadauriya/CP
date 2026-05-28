class Solution {
public:

/*

isme bhi exact K bol dia so u have to do same
<=k - <k = answer

*/

int solve(vector<int>&nums,int k){

    int l=0,h=0,count=0,odd=0;

    while(h<nums.size()){

        if(nums[h]%2!=0) odd++;  

        while(odd>k and l<=h){
            if(nums[l]%2!=0) odd--;
            l++;
        }

        count+=h-l+1;

        h++;
    }
    return count;
}
    int numberOfSubarrays(vector<int>& nums, int k) {

        int a=solve(nums,k);

        int b=solve(nums,k-1);

        return a-b;

    }
};
