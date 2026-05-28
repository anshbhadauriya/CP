class Solution {
public:
/*

We should only care about 0's

kyuki agr 0's k exceed kr gae too ham future subarray ko bhi nhi consider kr skte na hi current

so you just have to maintain subarray whose 0's are <=k

*/
    int longestOnes(vector<int>& nums, int k) {

        int l=0,h=0,maximum=0,zeros=0;

        while(h<nums.size()){

            if(nums[h]==0) zeros++;

            while(zeros>k and l<=h){

                if(nums[l]==0) zeros--;

                l++;
            }

            maximum=max(maximum,h-l+1);

            h++;

        }

        return maximum;
        
    }
};
