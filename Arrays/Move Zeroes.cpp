class Solution {
public:
/*
instead of moving all zero to right

move all non zeros to left

brute done

but optimal appraoch in not intutive

think it like ki hme non zero ele ko j pr rkhna hai

aur j ko try kro 0 ke sth chlane ka
*/
    void moveZeroes(vector<int>& nums) {

        int j=0;

        for(int i=0;i<nums.size();i++){

            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        
    }
};

/*
TC-> O(n)
SC-> O(1)
*/
