/*

2 cases ho skte hai-

yaa fir circular subarray maximum hoga mtlb array ka last ka aur shuru ka part
yaa maximum subarray bich me kabhi bhi hoga

case 1:
dekho agr circular subarray is maximum hai mtlb ki agr array hai [10,10,1,2,10,10]

too aisse case me normally kadane laga kr answer nhi milega

so uk ki agr left most + right most is maximum subarray so middle part is minimum subarray

so circulary subarray sum = total sum of array - minimum subarray

case 2 :

normally bich se maximum subarray nikal lo

*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {


        int curr_max=nums.front(),maximum=nums.front(),curr_min=nums.front(),minimum=nums.front(),total=nums.front();

        for(int i=1;i<nums.size();i++){

            curr_max=max(curr_max+nums[i],nums[i]); //extend or restart

            maximum=max(maximum,curr_max);

            curr_min=min(curr_min+nums[i],nums[i]);

            minimum=min(minimum,curr_min);

            total+=nums[i];
        }

        /*
        agr sare ele -ve hai too return maximum

        agr max(maximum,total-minimum); krdoge sare -ve wale case me too total-minimum will give 0 joki maximum hojaega aur answer galat hojaea
        */

        if(maximum<0){  
            return maximum;
        }

        return max(maximum,total-minimum);
        
    }
};
/*
TC-> O(n)
SC-> O(1)
*/
