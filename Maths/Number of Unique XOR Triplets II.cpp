/*

n^2 will work  

pehle pairs ka xor nikalo
*/
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        int n=nums.size();

        unordered_set<int>ans;
        unordered_set<int>st;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                st.insert(nums[i]^nums[j]);
                ans.insert(nums[i]);
            }
        }

        for(auto &x:st){

           
            for(int i=0;i<n;i++){
                ans.insert(x^nums[i]);
            }
        }

        return ans.size();


        
    }
};
