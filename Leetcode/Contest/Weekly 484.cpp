class Solution {
public:
    int residuePrefixes(string s) {
        int count=0;
        string temp;
        unordered_set<char>st;
        for(int i=0;i<s.size();i++){
            temp+=s[i];
            st.insert(s[i]);
            if(st.size()==temp.size()%3) count++;
        }
        return count;
    }
   
};

Q2->
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            unordered_set<int>st;
            for(int j=i;j<nums.size();j++){
                st.insert(nums[j]);
                sum=sum+nums[j];
                if(st.count(sum)) ans++;
            }
        }
        return ans;
    }
};
