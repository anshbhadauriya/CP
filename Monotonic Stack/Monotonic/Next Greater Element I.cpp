class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int>st;

        for(int i=nums2.size()-1;i>=0;i--) {
            while(!st.empty() && st.top() <= nums2[i]) { //sare chote elements ko remove kro
                st.pop();
            }

        if(st.empty()){  //agr koi element nhi bacha stack me too mtlb koi next greater nhi h
                mp[nums2[i]]=-1;
            } else{
                mp[nums2[i]]=st.top();  
            }

            st.push(nums2[i]);
        }

        vector<int>answer;
        for(int i=0;i<nums1.size();i++) {
            if(mp.find(nums1[i])==mp.end()) {
                answer.push_back(-1);
            } 
            else{
                answer.push_back(mp[nums1[i]]);
            }
        }

        return answer;
    }
};
