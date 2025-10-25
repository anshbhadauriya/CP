class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,high=*max_element(piles.begin(),piles.end());
        int minimum=INT_MAX;
        while(l<=high){
            int mid=l+(high-l)/2;
            long long count=0;
            for(int i=0;i<piles.size();i++){
               count=count+(piles[i]+mid-1)/mid;
            }
            if(count<=h){
                minimum=min(minimum,mid);
                high=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        return minimum;
        
    }
};
