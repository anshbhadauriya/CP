class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {

        vector<vector<int>>copy=mat;

        int n=mat.size(),m=mat[0].size();
        k=k%m;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int new_j;
                if(i%2==0){
                    new_j=(j+k)%m;  //isse leftshift
                }
                else{
                    new_j=(j-k+m)%m;  //right shift
                }
                if(mat[i][j]!=mat[i][new_j]) return false;
            }
            
        }

        return true;
        
    }
};
