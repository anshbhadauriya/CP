Q2->

class Solution {
public:
    bool check(int a,int b){
       vector<pair<int,int>>v1;
        while(a>0 or b>0){
            int last_a=a%10;
            int last_b=b%10;
            if(a!=0){
            a=a/10;
            }

            if(b!=0){
            b=b/10;
            }
            if(last_a!=last_b){
                v1.push_back({last_a,last_b});
                if(v1.size()>2){
                    return false;
                }
            }
        }
        if(v1.size()==1 or v1.size()>2){
            return false;
        }
        if(v1.size()==0){
            return true;
        }

        int a1=v1[0].first;
        int a2=v1[0].second;
        int b1=v1[1].first;
        int b2=v1[1].second;
        if(a1==b2 and a2==b1){
            return true;
        }
        return false;
    }
    int countPairs(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j] or check(nums[i],nums[j])){
                    count++;
                }
            }
        }
        return count;
    }
};
