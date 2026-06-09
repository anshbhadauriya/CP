class Solution {
public:
  /*
        
       just do merge sort and count at each breaking point


        */

        void countPairs(vector<int>&nums,int low,int mid,int high,int &cnt){

            int right=mid+1;

            for(int i=low;i<=mid;i++){

                while(right<=high and 1LL*nums[i]>(nums[right]*1LL*2)) right++;

                cnt+=right-(mid+1); //number of ele from mid+1 to right-1
            }
        }
int merge(vector<int>& nums, int low, int mid, int high) {
        
        int cnt = 0;

        int right = mid + 1;

        countPairs(nums,low,mid,high,cnt);

        // for (int i = low; i <= mid; i++) {
        //     while (right <= high && (long long)nums[i] > 2LL * nums[right]) {
        //         right++;
        //     }
        //     cnt += right - (mid + 1);
        // }

        vector<int> temp;

        int left = low;
        right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left++]);
        }

        while (right <= high) {
            temp.push_back(nums[right++]);
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

        return cnt;
    }


 int mergeSort(vector<int>& nums, int low, int high) {

        if (low >= high) return 0;

        int mid = low + (high - low) / 2;

        int cnt = 0;

        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid + 1, high);

        cnt += merge(nums, low, mid, high);

        return cnt;
    }
    int reversePairs(vector<int>& nums) {

        return mergeSort(nums,0,nums.size()-1);


    }
};