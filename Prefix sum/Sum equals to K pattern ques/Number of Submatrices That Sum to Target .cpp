class Solution {
public:

/*

Tricky ques

very similar to (560) Subarray Sum Equals K

bss starting point smjho

*/
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {

        int n=matrix.size(),m=matrix[0].size(),ans=0;


        vector<vector<int>>prefix(n,vector<int>(m,0));

        //row wise sum

        // cout<<"Row wise sum "<<endl;

        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<m;j++){

                sum+=matrix[i][j];

                prefix[i][j]=sum;

                // cout<<sum<<" ";

            }
            // cout<<endl;
        }

        for(int start_point=0;start_point<m;start_point++){

        for(int i=start_point;i<m;i++){ //i represents columns
            unordered_map<int,int>mp;
             mp[0]=1;
            int sum=0;
            for(int j=0;j<n;j++){  //j represents rows

            sum+=(start_point>0)? prefix[j][i]-prefix[j][start_point-1]: prefix[j][i]; //ek pehle wale col ko remove kro

                

                if(mp.count(sum-target)){
                    ans+=mp[sum-target];
                }

                mp[sum]++;
                
            }
        }

        }
        return ans;


        
    }
};
