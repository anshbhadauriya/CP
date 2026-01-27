Q1->

  class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int minimum=INT_MAX;
        int count=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]>nums[i]){
                count++;
            }
            else{
                count=1;
            }
        }
        cout<<count;
        return nums.size()-count;
        
    }
};


Q2->

  class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        deque<int>dq;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                dq.push_back(nums[i]);
            }
        }
        if(dq.empty()) return nums;
          k=k%dq.size();

          while(k--){
        int x=dq.front();
        dq.pop_front();
        dq.push_back(x);
          }

        int j=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                nums[i]=dq[j];
                j++;
            }
            
        }
        return nums;
        

        
    }
};
