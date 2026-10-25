Q1->
class Solution {
public:
    int toBinary(int num){

        int count=0;
        while(num>0){

            count+=num%2;
            num=num/2;
        }

        return count;
    }
    int calculateScore(int a, int b) {

        int s1=toBinary(a);
        int s2=toBinary(b);

        if(s1>=s2) return s1*s2;

        return s2/s1;
        
        
    }
};

/*

jisko sort krne se zyda diff mile usko sort kro

*/
Q2->
class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {

        int n=nums.size();

        long long ans=0;

        priority_queue<pair<long long,pair<long long,int>>>pq;

        for(auto curr:nums){

            string str=to_string(curr);

            sort(str.rbegin(),str.rend());

            long long ele=stoll(str);

            long long diff=ele-(1LL*curr);

            pq.push({diff,{ele,curr}});
            
        }

        while(k--){
            ans+=pq.top().second.first;
            pq.pop();
        }

        while(!pq.empty()){
            ans+=pq.top().second.second;
            pq.pop();
        }

        return ans;
        
    }
};
Q3->
/*
agr k distinct values hai so subarray is frequency staricase

constraints are small

har range k lie sequence pta hona chaiye

lets try btrue force first

worked!!

easy contest!!
*/

class Solution {
public:
    int countStaircase(vector<int>& nums) {

        int n=nums.size(),ans=0;

        for(int i=0;i<n;i++){
            
            unordered_map<int,int>mp;

            vector<int>temp;
            
            for(int j=i;j<n;j++){

                if(!mp.count(nums[j])) temp.push_back(nums[j]);

                mp[nums[j]]++;

                bool inValid=false;

                for(int k=0;k<temp.size();k++){

                    if(mp[temp[k]]!=k+1){

                        inValid=true;

                        break;
                    }
                }

                if(!inValid) ans++; 

                
            }
        }

        return ans;
    }
};
