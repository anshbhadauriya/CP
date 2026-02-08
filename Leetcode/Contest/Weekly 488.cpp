Q1->

  class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            int curr=nums[i];
            int sum=0,cnt=0;
            for(int j=i+1;j<nums.size();j++){
                sum=sum+nums[j];
                cnt++;
            }
            if(nums[i]>sum/cnt){
                ans++;
            }
            
        }
        return ans;
    }
};

Q2->

  class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long>st;

        for(int i=0;i<nums.size();i++){
           
            st.push_back(nums[i]);

            while(st.size()>=2 and st[st.size()-1]==st[st.size()-2]){
                long long sum=st[st.size()-1]+st[st.size()-2];
                st.pop_back();
                st.pop_back();
                st.push_back(sum);
            }
            
        }
        return st;
    }
};


Q3->

  class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        multiset<long long>st;
        
        long long l=0,h=0,count=0;
        while(h<nums.size()){


            st.insert(nums[h]);
            
            while(st.size()>0 and (*st.rbegin()-*st.begin())*st.size()>k){
                auto it=st.find(nums[l]);
                st.erase(it);
                l++;
            }
           count+=h-l+1;

            h++;
            
        }
        return count;
    }
};
