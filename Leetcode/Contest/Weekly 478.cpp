Q1->

class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        if(k>=nums.size()){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int same=0,count=0;
        int i=0;
        if(k==0){
            return nums.size();
        }
        while(n-(i+1)>=k and i<n-1){
            if(nums[i]==nums[i+1]){
                same++;
            }
            if(nums[i]<nums[i+1]){
                count=count+same+1;
                same=0;
            }
            i++;
           
        }
        return count;

    }
};


Q2->
class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char>st(s.begin(),s.end());
        return st.size();
    }
};

Q3->

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int minimum=INT_MAX;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            string temp=to_string(nums[i]);
            reverse(temp.begin(),temp.end());
            int curr=stoi(temp);

            if(mp.find(nums[i])!=mp.end()){
                minimum=min(minimum,abs(mp[nums[i]]-i));
            }
            else{
                mp[curr]=i;
            }
           
        }
        if(minimum==INT_MAX){
            return -1;
        }
        return minimum ;
    }
};

