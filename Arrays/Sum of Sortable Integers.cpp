class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        //k is sortable if
        // k%n==0 and we can sort nums in ascending order

        //partition nums into subarrays of size k
        //rotate each subarray any number of times

        //so first find possible divisor of n

        //then for each possible divisor you can take subarray for that and rotate any number of times, if array can be sorted so sum+=possible divisor

        // how can i find divisors of n??

        //so divisor will always be 1 and n itself

        //and we have to find remaining divisorss

        int n=nums.size();

        vector<int>divisors;

        

        

        

        //now find remaining divisors

        //if given nums is already sorted so answer is sum of all divisors

        //find divisors

        for(int i=1;i<=n/2;i++){
            if(n%i==0){
                divisors.push_back(i);
            cout<<i<<" ";
            }
        }

        //agr already sorted ho too

        // if(is_sorted(divisors.begin(),divisors.end())){
        //     int total=accumulate(divisors.begin(),divisors.end(),0);
        //     return total;
        // }

        cout<<endl;

        //now 3rd test case should work lets see


        //so we are getting divisors


        //now we have to sort it using rotations of length divisors[i]


        //make a vector which represents target



//         Then we have to check for two conditions if these conditions occur than the output will be -1 because we will never be able to obtain the non decreasing array :
// (i) If the maximum number from the current block is strictly greater than the minimum number from the next block.
// (ii) If while iterating through the block we find the count of dip>1 than we will never be able to make the array sorted in non decreasing through cyclic shifts.

    

    divisors.push_back(n);

    int ans=0;

    for(int i=0;i<divisors.size();i++){

        int j=0;

        bool temp=false;

        while(j<n-1){  //if max of curr block > min of next block..sare pehle hi check krlo
        if(j+divisors[i]<n){
        int maximum=*max_element(nums.begin()+j,nums.begin()+j+divisors[i]);  //curr block max

        int z=j+divisors[i];  //range

        int minimum=*min_element(nums.begin()+z,nums.begin()+z+divisors[i]);  //next block min

        if(maximum>minimum){
            temp=true;
            break;
        }

        }

        int count=0;

        for(int k=j;k<j+divisors[i]-1;k++){
            if(nums[k]>nums[k+1]) count++;
        }

        if(nums[j+divisors[i]-1]>nums[j]) count++;

        if(count>1){
            temp=true;
            break;
        }
        j+=divisors[i];

    }

    if(!temp) ans+=divisors[i];
    }
    return ans;
      
    }
};
