long long ke baad 1LL use kia jata hai jab long long me integer ki value assign kro, means m and k are integer but we are assigining it in temp which is long long!

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long temp=1LL*k*m;
        if(temp>bloomDay.size()){
            return -1;
        }
        if(temp==bloomDay.size()){
            return *max_element(bloomDay.begin(),bloomDay.end());
        }
        int l=1,h=*max_element(bloomDay.begin(),bloomDay.end());
        int minimum=INT_MAX;
        while(l<=h){
            int mid=l+(h-l)/2;
            int count=0;
            int adj=0;
   
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid){
                    ++adj;
                 
                }
                else{
                    adj=0;
                }
                if(adj==k){
                    count++;
                    adj=0;
                }

            }

            if(count>=m){
                h=mid-1;
                minimum=min(minimum,mid);
            }
            else{
                l=mid+1;
            }
        }
        return minimum;
    }
};
