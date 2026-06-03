class Solution {
public:

/*
Make a chain
and find longest chain
*/
    int longestConsecutive(vector<int>& nums) {

       unordered_set<int>st;

       for(auto x:nums) st.insert(x);

       int maximum=0;


       for(int i=0;i<nums.size();i++){

        int forward=nums[i]+1;
        int backward=nums[i]-1;
        int total_count=0;
        int forward_count=0,backward_count=0;

        if(st.count(nums[i])){

            st.erase(nums[i]);

            total_count+=1;

        while(st.count(forward)){
            forward_count++;
            st.erase(forward);
            forward++;
        }
        while(st.count(backward)){
            backward_count++;
            st.erase(backward);
            backward--;
        }

        total_count+=forward_count+backward_count;

        }

        maximum=max(maximum,total_count);


       }

       return maximum;
        
    }
};
