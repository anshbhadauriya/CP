class Solution {
public:
bool possible(vector<int>& batteries,long long target_minutes,long long &mid){
        for(int i=0;i<batteries.size();i++){
            target_minutes-=min((long long)batteries[i],mid);
            if(0>=target_minutes){  
                return true;   //check kro ki suppose kre hue minutes par sare computer chalenge ya nhi
                }
            }
            return false;

}
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l=*min_element(batteries.begin(),batteries.end());
        long long r=0;

        for(auto &x:batteries){
            r=r+x;
        }
        r=r/n;

        long long result;


        while(l<=r){

            long long mid=l+(r-l)/2;

            long long target_minutes=n*mid;
            if(possible(batteries,target_minutes,mid)){
                result=mid;
                l=mid+1;
            }
            else{
            r=mid-1;
            }
        }
        return result;
    }
};
