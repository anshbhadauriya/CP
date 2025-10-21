Q1->

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int x=k;
        unordered_set<int>st(nums.begin(),nums.end());
        while(st.count(k)){
            k=k+x;
        }
        return k;
    }
};


Q2->

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maximum=0;
        for(int i=0;i<nums.size()-1;i++){
            unordered_set<int>odd,even;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%2==0){
                    even.insert(nums[j]);
                }
                else{
                    odd.insert(nums[j]);
                }
                if(odd.size()==even.size()){
                    maximum=max(maximum,j-i+1);
                }
            }
        }
        return maximum;
    }
};
