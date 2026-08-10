class Solution {
public:
int ans=0;

bool isSafe(int row,int col,vector<vector<int>>&grid){
    int n=grid.size();
        int up_row=row-1;

    while(up_row>=0){  //up

        if(grid[up_row--][col]==1) return false;
    }

    int left_up_row=row-1,left_up_col=col-1;

    while(left_up_row>=0 and left_up_col>=0){
        if(grid[left_up_row--][left_up_col--]==1) return false;
    } 

    //right up diagonal

    int right_up_row=row-1,right_up_col=col+1;

    while(right_up_row>=0 and right_up_col<n){
        if(grid[right_up_row--][right_up_col++]==1) return false;
    } 

    return true;
}

void solve(int idx,int n,vector<vector<int>>grid){

    if(idx==n){
        ans++;
        return;
    }

    for(int i=0;i<n;i++){  //check kro ki idx wali row me kon kon se cell me queen rkh skte hai

    if(isSafe(idx,i,grid)){
        
        grid[idx][i]=1;

        solve(idx+1,n,grid);
        
        grid[idx][i]=0;
    }
    }

    
}
    int totalNQueens(int n) {

        vector<vector<int>>grid(n,vector<int>(n,0)); //0 means empty

         solve(0,n,grid);

         return ans;
        
    }
};
