Q1->
  class Solution {
public:

    bool isvalid(int curr,vector<int>&nums,int idx){

        int count=0,count2=0,ele=0,ele2=0;

        bool flag1=false,flag2=false;
        for(int i=0;i<idx;i++){
            if(curr>nums[i]) count++;

            ele++;
        }

        if(count==ele) return true;
        

        for(int i=idx+1;i<nums.size();i++){
            if(nums[i]<curr) count2++;

            ele2++;
        }

        if(count2==ele2) return true;
        // if(!flag1 or !flag2) return true;

        return false;

        
    }
    vector<int> findValidElements(vector<int>& nums) {

        vector<int>ans;

        

        for(int i=0;i<nums.size();i++){
            if(i==0 or i==nums.size()-1){
                ans.push_back(nums[i]);
                continue;
            }
            if(isvalid(nums[i],nums,i)){
                ans.push_back(nums[i]);
            }
        }

        return ans;
        
    }
};

Q2->

  class Solution {
public:
    string sortVowels(string s) {

        //descending order

        unordered_set<char>st{'a','e','i','o','u'};
        string temp;

        for(auto x:s){
            if(st.count(x)){
                temp.push_back(x);

                cout<<x<<" ";

            }
        }

        cout<<endl;

        map<char,int>mp;

        set<char>sett;

        string temp3;

        for(int i=0;i<temp.size();i++){
            if(!sett.count(temp[i])) temp3.push_back(temp[i]);

            sett.insert(temp[i]);
        }

        for(auto x:temp) mp[x]++;


        priority_queue<pair<int,pair<int,char>>>pq;

        int count=0;
        cout<<endl;
        for(auto x:temp3){
            pq.push({mp[x],{-count,x}});

            // cout<<x.second<<" "<<-count<<" "<<x.first<<endl;
            count++;
        }

        string ans="";

        while(!pq.empty()){
            int freq=pq.top().first;
            char ele=pq.top().second.second;
            pq.pop();

            while(freq--){
                ans+=ele;
            }


        }

        cout<<ans<<endl;

        int j=0;

        for(int i=0;i<s.size();i++){
            if(st.count(s[i])){
                s[i]=ans[j];
                j++;
            }
        }

        return s;





        
    }
};


Q3->

  class Solution {
public:
    long long minOperations(vector<int>& nums) {

        //any subarray increase with x

        //descending order

        
        int maximum=nums.front();

      

        //jo bhi sbse big diff return that

        long long total=0;

        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                total+=1LL*(nums[i-1]-nums[i]);
                
                
            }
            
        }

        return total;
        

        
        
    }
};
