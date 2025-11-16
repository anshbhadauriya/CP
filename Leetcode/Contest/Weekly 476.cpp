class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=nums[nums.size()-1];
        int b=nums[nums.size()-2];
        int c=nums[0];
        return (a+b)-c;
    }
};

Q2->
class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a=0,b=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                a++;
            }
            else{
                b++;
            }
        }
        return a-min(a,b)+b-min(a,b);
    }
};
