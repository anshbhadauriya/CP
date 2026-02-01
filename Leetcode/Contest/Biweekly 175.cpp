Q1->
class Solution {
public:
    string reverseByType(string s) {
        string lc;
        string special;
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i]) and islower(s[i])){
                lc.push_back(s[i]);
                continue;
            }
            else{
                special.push_back(s[i]);
            }
        }

        reverse(lc.begin(),lc.end());
        reverse(special.begin(),special.end());

        string answer;
        int j=0,k=0;

        for(int i=0;i<s.size();i++){
            if(islower(s[i]) and isalpha(s[i])){
                answer.push_back(lc[j]);
                j++;
            }
            else{
                answer.push_back(special[k]);
                k++;
            }
        }
        return answer;
    }
};

Q2->
class Solution {
public:
    int minimumK(vector<int>& nums) {
        int l=1,h=*max_element(nums.begin(),nums.end())+nums.size();
        int ans=h;
        while(l<=h){
            long long k=l+(h-l)/2;

            long long count=0;
            for(int i=0;i<nums.size();i++){
                count+=(nums[i]+k-1)/k;
            }
            if(count<=k*k){
                h=k-1;
                ans=k;
            }
            else{
                l=k+1;
            }
        }
        return ans;
    }
};
