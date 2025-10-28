class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=1,h=accumulate(weights.begin(),weights.end(),0);
        int minimum=INT_MAX;
       
        while(l<=h){
            int mid=l+(h-l)/2;
            int temp_weight=0;
            int count=1;
             bool flag=false;

            for(int i=0;i<weights.size();i++){
               if(weights[i]>mid){
                flag=true;
                break;
               } 
                if(temp_weight+weights[i]<=mid){
                    temp_weight+=weights[i];
                }
                else{
                    count++;
                    temp_weight=0;
                    i--;
                }
            }
           
            if(!flag and count<=days){
                 
                minimum=min(minimum,mid);
                h=mid-1;
            }
            else{
                cout<<count<<" ";
                l=mid+1;
            }
        }
        return minimum;
    }
};
