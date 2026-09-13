class Solution {
public:
int partition_algo(int l,int h,vector<int>&nums){

    int p=nums[l];
    int i=l+1;
    int j=h;

    while(i<=j){

        if(nums[i]<p and nums[j]>p){  //pivot se pehle pivot se bade ele hone chaiye aur pivot ke baad usse chote agr aissa nhi h too swap
            swap(nums[i],nums[j]);
            i++;
            j--;
        }

         if(nums[i]>=p){
            i++;
        }
         if(nums[j]<=p){
            j--;
        }
    }
    swap(nums[l],nums[j]);

    return j;  //p is at jth
}
    int findKthLargest(vector<int>& nums, int k) {

        int n=nums.size(),l=0,h=n-1,pivot=0;

        while(true){

            pivot=partition_algo(l,h,nums);

            if(pivot==k-1) return nums[pivot];

            else if(pivot>k-1){
                h=pivot-1;
            }
            else l=pivot+1;
        }

        return nums[pivot];


        
    }
};
