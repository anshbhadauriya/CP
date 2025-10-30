// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int ans=-1;
        int maximum=0;
        for(int i=0;i<arr.size();i++){
            
            vector<int>curr(arr[i].begin(),arr[i].end());
            
            int l=0,h=curr.size()-1;
            while(l<=h){
                int mid=l+(h-l)/2;
                
                if(curr[mid]==1){
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            int onesCount=curr.size() - l;

            if(onesCount>maximum) {
                maximum=onesCount;
                ans=i;
            }
            
        }
        return ans;
        
    }
};
