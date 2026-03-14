Q1->
  class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x:nums) mp[x]++;

        for(auto x:nums){
            if(x%2==0 and mp[x]==1) return x;
        }
        return -1;
        
    }
};

Q2->

  class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        vector<long long>prefix;
        long long maximum=-1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>maximum){
                maximum=nums[i];
            }

            long long gcdd=gcd(maximum,nums[i]);

            prefix.push_back(gcdd);
        }

        sort(prefix.begin(),prefix.end());

        long long sum=0;

        int i=0,j=prefix.size()-1;

        while(i<j){
            long long small=prefix[i];
            long long large=prefix[j];

            long long gcdd=gcd(small,large);

        sum+=gcdd;
        i++;
        j--;

            
        }
    return sum;

    
        
    }
};

Q3->

  class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {

        //same array me swap kro i    j

        //opposite array me i   i swap kro

        //sbse pehle free cost ko utilize kro

        //agr dono array ke element ki freq same hogi too always 0

        vector<int>temp1=nums1;

        vector<int>temp2=nums2;


        sort(temp1.begin(),temp1.end());

        sort(temp2.begin(),temp2.end());

        if(temp1==temp2) return 0;


        //maan loo tumne dono ko sort kr diaa

        //abh unnhe same kro 

        //agr kabhi kisi element ki freq odd hai return -1

        unordered_map<int,int>mp;
        unordered_map<int,int>freq1;
        unordered_map<int,int>freq2;

        for(auto x:nums1){
            freq1[x]++;
            mp[x]++;
        }
        for(auto x:nums2){
            freq2[x]++;
            mp[x]++;
        }

        for(auto x:mp) {
            if(x.second%2!=0) return -1;
        }

        //kisi trh dono array ki freq same kro


        

        

        int count=0;
        for(auto x:mp){
            int curr=x.first;
            
                count+=abs(freq1[curr]-freq2[curr]);
                
                
                
            }
        

        

        


        return count/4;


        

        
        
    }
};
