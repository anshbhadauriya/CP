/*
O(n) is simple

log n approach:

dekho ideally jo bhi ele hai vo ele == idx+1 hona chaiye at each cell
so if index 2 pr 4 hai too ek ele left side me missing hai kyuki ideally 3 hona chaiye tha

so nums[i] - (i+1) bata dega ki till ith index kitne ele missing hai
*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int l=0,h=arr.size()-1;

        while(l<=h){

            int mid=l+(h-l)/2;

            int missing_till_mid=arr[mid]-(mid+1);

            if(missing_till_mid<k) l=mid+1;

            else h=mid-1;
        }

        return l+k;  //yeh smjh nhi aarha
        
    }
};
