class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int l=0,r=m-1;

        while(l<=r){

            int mid=l+(r-l)/2;

            // row index find krooo of the maximum element in this column
            int maxRow=0;
            for(int i=0;i<n;i++){
                if(mat[i][mid]>mat[maxRow][mid]){
                    maxRow=i;
                }
            }

           int left,right;
           
            if(mid-1>=0) {
                left=mat[maxRow][mid-1];
            } else{
                left=-1;
            }

          
            if(mid+1<m) {
                right=mat[maxRow][mid+1];
            } else{
                right=-1;
            }

            if(mat[maxRow][mid] > left && mat[maxRow][mid] > right) {
                return {maxRow,mid};
            } else if(left>mat[maxRow][mid]) {
                r=mid-1;
            } else{
                l=mid+1;
            }

        }
        return {-1,-1};
    }
};