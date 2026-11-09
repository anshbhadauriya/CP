class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {

        int i=0,j=0;

        string temp1="";
        string temp2="";

        vector<vector<string>>ans;

        while(i<s1.size() and j<s2.size()){

            if(s1[i]!=s2[j]){

            temp1+=s1[i];
            temp2+=s2[j];
            }

        else if(s1[i]==s2[j] and (temp1.size() or temp2.size())){
            ans.push_back({temp1,temp2});

            temp1.clear();
            temp2.clear();
        }

        i++;
        j++;
        }

    if(temp1.size() or temp2.size()) ans.push_back({temp1,temp2});

    return ans;
        
    }
};


/*

i to n-1 sort in descending order

agr kisi point ke baad sab kuch sort krne par target ke barabar so count++


1 5 6 4 6

1 5 6 6 4

withsort wale equals hone chaiye 

soo at each idx we need to know ki

remainign ele yani ki suffix  descending order me hai in target
if yes
then ele suffix ele of nums and target should be same 
yani ki sbki freq same honi chaiye

but yeh kaise pta chlega ki till i suffix is anagram

we can use hashmap or multiset ig

size 0 maintain kr skte h


*/

class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {

       int n=nums.size();

        vector<bool>anagram(n,false);
        vector<int>isIncreasing(n);

        unordered_map<int,int>mp;

        for(int i=n-1;i>=0;i--){

            mp[nums[i]]++;

            mp[target[i]]--;

            if(mp[target[i]]==0) mp.erase(target[i]);
            if(mp[nums[i]]==0) mp.erase(nums[i]);

       
            if(mp.empty()) anagram[i]=true;
            else anagram[i]=false; 
            
        }

        // cout<<endl;

       // for(auto x:anagram) cout<<x<<" ";
        // cout<<endl;

        isIncreasing[n-1]=true;


        for(int i=n-2;i>=0;i--){

            if(target[i]>=target[i+1]) isIncreasing[i]=true;

            else break;

            
        }


        //for(auto x:isIncreasing) cout<<x<<" ";

        //cout<<endl;

        int ans=0,prefNotEquals=0;

        for(int i=0;i<n;i++){
            
            if(prefNotEquals) break;

            if(isIncreasing[i] and anagram[i]) ans++;
            if(nums[i]!=target[i]) prefNotEquals++;
        }

        return ans;
        
    }
};
