class Solution {
public:

/*
Piche se first ascending dhundo (of 2 numbers) or u can say piche se first adjacent jo 
nums[i]<nums[i+1]  bcs after making them descending that will make smallest change and make slightest bigger permuation as compare to curr

unko swap kro aur i ke baad wale sare ele ko reverse kro

intution behind this:

copy me random test case ke examples dekhi ip op ke

you will find a pattern


*/
    void nextPermutation(vector<int>& nums) {

        int n=nums.size();

        //step 1 find first nums[i]<nums[i+1] (ascending pair)  from back

        int idx=-1;


        for(int i=n-1;i>=1;i--){

            if(nums[i]>nums[i-1]){
                idx=i-1;
                break;
            }
        }

        if(idx==-1){  //mtlb descending order me sorted hai

        reverse(nums.begin(),nums.end());
        

        }

        else{

            //abh minimum numbers greater than nums[i] find kro jo i ke baad aata ho

            int minimum=INT_MAX,idx2=-1;

            for(int j=idx+1;j<n;j++){

                if(nums[j]>nums[idx] and nums[j]<=minimum){  //<= isslie kyuki if there are duplicates we must choose from right most ele of duplicate
                    minimum=nums[j];
                    idx2=j;
                }
            }

            swap(nums[idx],nums[idx2]);

            reverse(nums.begin()+idx+1,nums.end());
        }



        

    }
};
