class Solution {
public:
    int minMergedInteger(vector<int>& nums) {

        vector<string>temp;

        int minimum=INT_MAX;

        for(int i=0;i<nums.size()-1;i+=2){

            string a=to_string(nums[i]);
            string b=to_string(nums[i+1]);
            string c=a+b;

            minimum=min(minimum,stoi(c));

            
        }

        return minimum;
        
    }
};

/*
nums -> 1,n
locked[i]=1 locked 
if 0 so unlocked

operations:

i aur i+1 dono 0 hone chaiye aur swap krdo (no cost)
kisi bhi idx ko lock se unlock kr skte ho  (at most k)

so yeh count krna hai ki kitne operations lge to sort in increasing order

insertion sort?

easyy

*/
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {

        int n=nums.size(),operations=0;

        for(int i=1;i<n;i++){

            int idx=i;

            while(idx-1>=0 and nums[idx]<nums[idx-1]){

                if(locked[idx]==1){
                    locked[idx]=0;
                    k--;
                    operations++;
                }
                
                if(locked[idx-1]==1){
                    locked[idx-1]=0;
                    k--;
                    operations++;
                }

                if(k<0) return -1;

                    swap(nums[idx],nums[idx-1]);
                    idx--;

                    operations++;
                
            }


        }

        return operations;


        
    }
};
