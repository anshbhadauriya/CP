class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        
        int h=0,n=arr.size(),ans=0,sum=0;
        
        unordered_map<int,int>mp;
        
        mp[0]=-1;
        
        while(h<n){
            
            sum+=arr[h];
            
            if(sum==k) ans=h+1;
            
            if(mp.count(sum-k)){
                
                ans=max(ans,h-mp[sum-k]);
            }
            
            if(!mp.count(sum)){  //To maximize the length, we want previous_index to be as small as possible
                mp[sum]=h;
            }
            
            h++;
            
        }
        
        return ans;
        
    }
};
