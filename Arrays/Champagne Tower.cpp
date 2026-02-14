class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>grid(101,vector<double>(101,0.00000));

        grid[0][0]=double(poured);

        for(int i=0;i<100;i++){
            for(int j=0;j<=i;j++){  //i tak hi jao kyuki observe kro diagram me ki ith row me ith glass hi bhar paega uske ange jane ki zaroort nhi kyuki champagne waha tak kabhi pahuch hi nhi paegi
        
            if(grid[i][j]>1){
                double rem=(grid[i][j]-1)/2;   //-1 isslie kyuki current cell me ek too rakhna hi hai aur divide by 2 isslie kyuki 2 part me divide krna hai
                grid[i][j]=1;
                grid[i+1][j]+=rem;
                grid[i+1][j+1]+=rem;
            }
            }
        }

        return grid[query_row][query_glass];

            
        
    }
};