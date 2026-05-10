Q1->

  class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {

        vector<int>temp(nums.rbegin(),nums.rend());

         vector<int>ans(nums.begin(),nums.end());

        for(auto x:temp) ans.push_back(x);

        return ans;
        
    }
};

Q2->

  class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {


        string s="";


        for(auto x:chunks) s+=x;

        unordered_map<string,int>mp;

        int n=s.size();

       

        for(int i=0;i<n;i++){

            //check kro

            if(s[i]>='a' and s[i]<='z'){

                string t="";

                int j=i;

                while(j<n){

                    if(s[j]>='a' and s[j]<='z') t+=s[j];

                    else if(s[j]=='-' and j-1>=0 and j+1<n and s[j-1]>='a' and s[j-1]<='z'  and s[j+1]>='a' and s[j+1]<='z'){
                        t+=s[j];
                    }
                else break;

            j++;
                }

            mp[t]++;
i=j;
                
            }



        }

vector<int>ans;



for(auto x:queries){
    ans.push_back(mp[x]);

    cout<<ans.back()<<" ";
}

return ans;

        

            
    }
};


Q3->

class Solution {
public:
    long long minArraySum(vector<int>& nums) {


        /*

        Har number ke sare divisor check kro, for example

        if n=16

        1,16
        2,8
        4,4

        */
        

        sort(nums.begin(),nums.end());

        unordered_set<int>st;

        long long total=0;


        for(int i=0;i<nums.size();i++){

            int curr=nums[i];

            int ans=nums[i];



            for(int j=1;j*j<=curr;j++){

                if(nums[i]%j==0){

                    if(st.count(j)){

                        ans=min(ans,j);
                    }

                    if(st.count(curr/j)){

                        ans=min(ans,curr/j);
                    }

                    
                }
            }

            st.insert(ans);

            total+=ans;

        }


        return total;



        
    }
};
