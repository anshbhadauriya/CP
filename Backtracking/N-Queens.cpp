class Solution {
public:

vector<vector<string>>result;

bool isSafe(vector<string>board,int row,int col,int n){

    /*
    bss 3 direction se check krne ki zaroort hai 
    up
    left up
    right up

    bcs abhi niche wali rows me queen too rkhi hi nhi hai as we are travelling from first row to last 

    */

    int up_row=row-1;

    while(up_row>=0){  //up

        if(board[up_row--][col]=='Q') return false;
    }

    int left_up_row=row-1,left_up_col=col-1;

    while(left_up_row>=0 and left_up_col>=0){
        if(board[left_up_row--][left_up_col--]=='Q') return false;
    } 

    //right up diagonal

    int right_up_row=row-1,right_up_col=col+1;

    while(right_up_row>=0 and right_up_col<n){
        if(board[right_up_row--][right_up_col++]=='Q') return false;
    } 

    return true;


}

void solve(int row,int n,vector<string>board){

    if(row==n){
        result.push_back(board);
        return;
    }

    for(int col=0;col<n;col++){

        if(isSafe(board,row,col,n)){   //check kro ki koi dusri queent too attack  nhi kr rhi

            board[row][col]='Q';    //try this possibility

            solve(row+1,n,board);   //next row me queen rkho and do same here 

            board[row][col]='.';  //abh backtrack kro 
        }
    }

}

    vector<vector<string>> solveNQueens(int n) {

        vector<string>board;

        string temp(n,'.');

        for(int i=1;i<=n;i++) board.push_back(temp);

        solve(0,n,board);

        return result;

        
        
    }
};

/*
TC->

isSafe() = O(n)

Row 0 : n choices

Row 1 : n-1 choices

Row 2 : n-2 choices

...

Row n-1 : 1 choice

n × (n-1) × (n-2) × ... × 1
= n!

Number of states × Cost per state

= O(n!) × O(n)

Total Time Complexity = O(n · n!)

Sc-> 

O(n²) + O(n)
= O(n²)



*/
