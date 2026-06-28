class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {

        long long total=0;

        sort(nums.rbegin(),nums.rend());

        for(int i=0;i<k;i++){

            long long a = nums[i];

            // long long b=nums[i] *mul;

            if(mul>0 and 1LL* nums[i]*mul>a){
                total+=1LL*mul*nums[i];
                mul--;
            }
            else total+=a;
            
        }

        return total;
        
    }
};

class Solution {
public:

    bool ismerging(int l1,int h1,int l2,int h2){

        if(l1>h2+1 or h1+1<l2){
            return false;
        }

    return true;
    }
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& intervals, int freeStart, int freeEnd) {

        //sbse pehle merge interval

        sort(intervals.begin(),intervals.end());

        vector<vector<int>>result;

        for(auto x:intervals){
            if(result.empty()){
                result.push_back(x);
                continue;
            }

            int n=result.size();

            int l2=x[0],h2=x[1];

            int l1=result.back()[0],h1=result.back()[1];

            if(ismerging(l1,h1,l2,h2)){
                int new_l=min(l1,l2);
                int new_h=max(h1,h2);

                result[n-1][0]=new_l;
                result[n-1][1]=new_h;
            }
            else{
                result.push_back(x);
            }
        
        }

        vector<vector<int>>ans;

        //abh start free wale check

        for(auto x:result){

            int l=x[0],h=x[1];

            if(l>freeEnd or freeStart>h){
                ans.push_back({l,h});
            }
            else if(freeStart <=l and freeEnd>=h) continue;

            else if(l<freeStart and h<=freeEnd) ans.push_back({l,freeStart-1});

            else if(l>=freeStart and h>freeEnd) ans.push_back({freeEnd+1,h});
            else{ ans.push_back({l,freeStart-1});
            ans.push_back({freeEnd+1,h});
                }
        }

        return ans;
        
    }
};
