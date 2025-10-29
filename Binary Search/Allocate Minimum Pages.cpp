class Solution {
public:
    bool isPossible(vector<int> &arr, int k, int mid) {
        int studentCount=1;
        int pageSum=0;

        for(int pages:arr) {
            if(pageSum+pages<=mid) {
                pageSum+=pages;
            } else{
                studentCount++;
                if(studentCount > k || pages>mid) {
                    return false;
                }
                pageSum=pages;
            }
        }
        return true;
    }

    int findPages(vector<int> &arr, int k) {
        int n=arr.size();
        if(k>n) return -1;

        int low=*max_element(arr.begin(), arr.end());
        int high=accumulate(arr.begin(), arr.end(), 0);
        int ans=-1;

        while(low<=high) {
            int mid=low+(high-low)/2;

            if(isPossible(arr,k,mid)) {
                ans=mid;
                high=mid-1;  
            } else{
                low=mid+1;  
            }
        }

        return ans;
    }
};
