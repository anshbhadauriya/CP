Set appraoch (easy)->
TC-> O(n*m)
SC-> O(n+m)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        unordered_set<int>row,col;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){

                if(row.count(i) or col.count(j)){
                    matrix[i][j]=0;
                }
            }
        }
        
        
    }
};


Most optimized->

TC-> O(m) + O(n) + O(n*m) + O(n*m) + O(m) + O(n)
= O(2*n*m + 2*n + 2*m)
= O(n*m)

  SC-> 0(1)
class Solution {
public:

/*

Ham first row and first column ke through pta krege ki current element ko 0 krna hai ya nhi
it means agr current element ke row ka first element 0 hai too mtlb vo element 0 hoga
yaa fir current element ke column ka first element 0 hai too vo element bhi 0 hoga 

ek trh se agr first kisi row ka firs element 0 hai too pura column zero hoga
aur row ka first element 0 hai too puri row 0 hogi

Important note: fir row aur col ko alg se krna hoga kyuki matrix bigad jaega 

notebook me try krna yeh example fir smjh jaoge
1 1 1
1 0 1
1 1 1

isslie ham first row aur col ko alg se check krege aur pta krege ki kya first row aur col me zero hai, agr 0 hai too baad me puri first row ya col ko 0 kr dena

*/
    void setZeroes(vector<vector<int>>& matrix) {

        int n=matrix.size(),m=matrix[0].size();

        //pehle first row dekhlo 

        bool kya_first_row_me_zero_hai=false,kya_first_col_me_zero_hai=false;


        for(int i=0;i<m;i++){

            if(matrix[0][i]==0){
                kya_first_row_me_zero_hai=true;
                break;
            }
        }


        //first col check

        for(int i=0;i<n;i++){

            if(matrix[i][0]==0){
                kya_first_col_me_zero_hai=true;
            }
        }


        //abh har cell me (exculding first row and col) me check kro ki 0 hai, if yes so uss row ke and col ke first ele ko 0 mark krke indicate kro


        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        //abh check kro jis bhi cell ke first row ya col me 0 hai mtlb vo ele bhi 0 hoga

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][0]==0 or matrix[0][j]==0) matrix[i][j]=0;
            }
        }


        //abh first row and first col ko zero banado if there was 0 initially in first row and col

        if(kya_first_row_me_zero_hai){

            for(int i=0;i<m;i++){
                matrix[0][i]=0;
            }
        }

        if(kya_first_col_me_zero_hai){

            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }

        

    }
};
