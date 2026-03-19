class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {

        //same like prefix but store x and y freq 
        
        int n=grid.size();
        int m=grid[0].size();


        vector<vector<pair<int,int>>>prefix(n,vector<pair<int,int>>(m,{0,0}));

        int count=0;
        for(int i=0;i<n;i++){
            int x=0,y=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X') x++;
                else if(grid[i][j]=='Y') y++;
                prefix[i][j]={x,y};

                if(i>0){
                    prefix[i][j]={prefix[i-1][j].first+x,prefix[i-1][j].second+y};
                }
                int a=prefix[i][j].first;
                int b=prefix[i][j].second;

                if(a>0 and a==b) count++; 
            }
        }

        

        // for(int col=0;col<m;col++){
        //     int x=0,y=0;
        //     for(int row=0;row<n;row++){

        //         int a=prefix[row][col].first;
        //         int b=prefix[row][col].second;

        //         x+=a;
        //         y+=b;
        //         prefix[row][col]={x,y};

        //         if(x>0 and x==y) count++;


        //     }
        // }

        return count;
        
    }
};
