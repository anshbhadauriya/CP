Q1->
  class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int k2=k;
        sort(nums.begin(),nums.end());
        int maximum=0,minimum=0;
        int i=nums.size()-1;
        while(i>=0 and k){
            maximum=maximum+nums[i];
            cout<<nums[i]<<" ";
            --k;
            i--;
        }
        for(int i=0;i<k2;i++){
            minimum+=nums[i];
        }
        return abs(minimum-maximum);
    }
};

Q2->

  class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string result;

        string curr;
        int i=0;
        int countt=0;

        while(ss>>curr){
            int vowels=0;
            if(i==0){
                for(int j=0;j<curr.size();j++){
            if(curr[j]=='a' or curr[j]=='e' or curr[j]=='i' or curr[j]=='o' or curr[j]=='u'){
                        countt++;
                    }
                }
                i++;
                result=result+curr;
                result=result+' ';
                continue;
                
            }
            for(int j=0;j<curr.size();j++){
                if(curr[j]=='a' or curr[j]=='e' or curr[j]=='i' or curr[j]=='o' or curr[j]=='u'){
                    vowels++;
                }
                
            }
            if(vowels==countt){
                reverse(curr.begin(),curr.end());
            }
            result+=curr;
            result+=' ';
            i++;
            
        }
        if(result.back()==' '){
            result.pop_back();
        }
        return result;
    }
};
