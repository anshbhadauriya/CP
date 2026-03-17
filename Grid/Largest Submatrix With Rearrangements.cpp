class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {


        //har point par jakr height * width

        int ans=0;

        int n=matrix.size(),m=matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1 and i-1>=0){
                    matrix[i][j]+=matrix[i-1][j];
                }
            }

            vector<int>curr=matrix[i];

            sort(curr.rbegin(),curr.rend());

            for(int i=0;i<curr.size();i++){
                ans=max(ans,curr[i]*(i+1));  //curr[i] denotes ki current cell ki height kitni hai and i+1 denotes width 
            }

           
            }

            return ans;
        
        
    }
};
