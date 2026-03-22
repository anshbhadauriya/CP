class Solution {
public:

//90 degree rotate krne ke lie 2 steps hote hai
//transpose
//reverse each row 
void rotate(vector<vector<int>>& mat){
    int n=mat.size(),m=mat[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){   //i+1 isslie taki dusri bar swap na hojae same element
            swap(mat[i][j],mat[j][i]);  //transpose kro
        }
    }
    for(auto &curr:mat) reverse(curr.begin(),curr.end());


}
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        for(int i=0;i<4;i++){
            if(mat==target) return true;
            else rotate(mat);
        }

        return false;


    }
};
