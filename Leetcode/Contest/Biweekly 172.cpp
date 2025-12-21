class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(),i=n-1;
        set<int>st;

        while(i>=0 and !st.count(nums[i])){
            st.insert(nums[i]);
            i--;
        }
        int rem=i+1;
        int op=rem/3;
        if(rem%3!=0){
            op++;
        }
        return op;
    }
};

Q2->
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int>r0,r1,r2;
        for(auto x:nums){
            if(x%3==0){
                r0.push_back(x);
            }
            else if(x%3==1){
                r1.push_back(x);
            }
            else {
                r2.push_back(x);
            }
        }

        sort(r0.rbegin(),r0.rend());
        sort(r1.rbegin(),r1.rend());
        sort(r2.rbegin(),r2.rend());
        int maximum=0;

        if(r0.size()>=3){
            maximum=max(maximum,r0[0]+r0[1]+r0[2]);
        }
        if(r1.size()>=3){
            maximum=max(maximum,r1[0]+r1[1]+r1[2]);
        }
        if(r2.size()>=3){
            maximum=max(maximum,r2[0]+r2[1]+r2[2]);
            
        }
        if(!r0.empty() and !r1.empty() and !r2.empty()){
            maximum=max(maximum,r0[0]+r1[0]+r2[0]);
        }
        return maximum;

        
    }
};
