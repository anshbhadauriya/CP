class Solution {
public:
    int longestMountain(vector<int>& arr) {

        int n=arr.size();
        vector<int>increasing(n),decreasing(n);

        int count=1;


        for(int i=0;i<arr.size();i++){

            if(i==0){
                increasing[i]=1;

               
                continue;
            }

            if(arr[i]>arr[i-1]){
                count++;
            }
            else count=1;

            increasing[i]=count;

           

        }

        

        count=1;

        for(int i=n-1;i>=0;i--){

            if(i==n-1){

                decreasing[i]=1;
               
                continue;
            }

            if(arr[i]>arr[i+1]){
                count++;
            }
            else count=1;

            decreasing[i]=count;

        }

       

        for(int i=0;i<n;i++){
            if(increasing[i]==1) increasing[i]=0;
            if(decreasing[i]==1) decreasing[i]=0;
        }

        int ans=0;
        for(int i=0;i<n;i++){

            if(increasing[i]==0 or decreasing[i]==0) continue;

            int peak=increasing[i]+decreasing[i]-1;

            ans=max(ans,peak);
        }

        return ans;
        
    }
};
