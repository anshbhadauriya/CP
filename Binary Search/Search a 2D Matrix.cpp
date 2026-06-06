class Solution {
public:
/*
the idea is very simple, 2d matrix ko 1d matrix maano
usme binary search lga do


mid nikalo normally
fir agr mid wale idx se row pta krni haii too notice that

har m(no. of cols) interval ke bad row increase ho rhi, so row=mid/m

aur col hamesha m andr hi rhega so col=mid%m

suppose ki 4 column hai (m=4)
so mtlb:
0th row me 4 ele
1st row me 4 ele
3rd row me 4 ele
4th row me 4 ele


so every 4 idx row change so 

row=mid/m;



The column numbers repeat like this:

Index:  0 1 2 3 | 4 5 6 7 | 8 9 10 11

Col:    0 1 2 3 | 0 1 2 3 | 0 1  2  3

col=mid%m



*/
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int l=0,h=(n*m)-1;

        while(l<=h){
            int mid=l+(h-l)/2;

            int row=mid/m;
            int col=mid%m;

            if(matrix[row][col]==target) return true;

            else if(matrix[row][col]>target)  h=mid-1;

            else l=mid+1;
        }

        return false;
    }
};
