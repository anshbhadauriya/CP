class Solution {
public:

/*
Unintuitive algo
majority ele agr n/2 hai too vo hmehsa minority ko remove kr skta hai

har ele ko majority element consider kro 

*/
    int majorityElement(vector<int>& nums) {
        int majority_element=0;

        int count=0;

        for(auto x:nums){
            if(count==0){
             majority_element=x;
             count++;
            }  

            else if(x==majority_element) count++;

            else count--;
        }
        return majority_element;
    }
};
