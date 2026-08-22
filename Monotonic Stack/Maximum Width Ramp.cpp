/*
basically hmne sare decreasing ele stack me dal die 

too st ke top pr sbse chota ele hoga

too nums ko piche se traverse kro diff count kro
*/
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        int n=nums.size();
        int ans=0;

        stack<int>st;

        for(int i=0;i<n;i++){
            if(i==0){
                st.push(i);

                //cout<<nums[i]<<" ";
                continue;
            }

            if(nums[i]<nums[st.top()]){
                st.push(i);

                //cout<<nums[i]<<" ";
            }

        }

        for(int i=n-1;i>=0;i--){

            while(st.size() and nums[i]>=nums[st.top()]){
                ans=max(ans,i-st.top());
                st.pop();
            }
        }

        return ans;


        
    }
};
