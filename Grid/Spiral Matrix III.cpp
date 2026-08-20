class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int n, int m, int rStart, int cStart) {

        vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}}; //east south west north

        vector<vector<int>>result;

        int step=0,dir=0;

        result.push_back({rStart,cStart});

        while(result.size()<n*m){

            if(dir==0 or dir==2) step++;  //agr direction east ho ya west so step ko badao

            for(int i=0;i<step;i++){

                rStart+=directions[dir][0];
                cStart+=directions[dir][1];

                if(rStart<n and rStart>=0 and cStart<m and cStart>=0) 
                result.push_back({rStart,cStart});
            }

            dir=(dir+1)%4;  //direction change kro
        }

        return result;
        
    }
};
