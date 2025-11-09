Q1->
  class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int minimum=INT_MAX;
        if(nums.size()<2){
            return -1;
        }
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]==nums[j] and nums[j]==nums[k]){
                        int ans=abs(i-j)+abs(j-k)+abs(k-i);
                        minimum=min(minimum,ans);
                    }
                }
            }
        }
        if(minimum==INT_MAX){
            return -1;
        }
        return minimum;
    }
};

Q2->

  class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int minimum=INT_MAX;
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<nums.size();i++){
            auto &vec=mp[nums[i]];
            vec.push_back(i);
                if(vec.size()>=3){
                int i1=vec[vec.size()-3];
                int i2=vec[vec.size()-2];
                int i3=vec[vec.size()-1];
                int distance=abs(i1-i2)+abs(i2-i3)+abs(i3-i1);
                    minimum=min(minimum,distance);
                
               
            }
        }
        if(minimum==INT_MAX){
            return -1;
        }
        return minimum;
        
        
    }
};
