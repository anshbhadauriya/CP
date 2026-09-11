/* 
grid[i][j] -> cost of visiting cell
start at 0,0 aur last cell tk jana h n-1,m-1
charo directions jaa skte h
cost of path is sum of values of cell which we have visited we can visit same cell multiple times aur har bar uski cost add hogi k turns hai hamare paas 
return -1 if no path exists
so we can use dp ig bcs atmost k turns hai..once k becomes 0 so cyclic nature khtm hojaega lets try dp first but we have to keep track of direction
so 0 starting 1 right 2 left 3 down 4 up

states-> i,j,k,direction

so 4d dp prolly
might gve MLE

worked!!
*/
class Solution { 
public: 
// #define ll long long 
int n,m; 
long long dp[76][76][76][5];
long long solve(int i,int j,int direction,vector<vector<int>>&grid,int k){ 
 
    if(i==n-1 and j==m-1){ 
        return grid[i][j]; 
    } 

    if(dp[i][j][k][direction]!=-1) return dp[i][j][k][direction];
 
    long long up=LLONG_MAX,down=LLONG_MAX,left=LLONG_MAX,right=LLONG_MAX; 
 
    if(direction==0){ //starting 
    if(j+1<m){ 
    long long temp=solve(i,j+1,1,grid,k); 
    if(temp!=LLONG_MAX) 
    right=grid[i][j]+temp; 
 
    } 
    if(i+1<n){ 
    long long temp=solve(i+1,j,3,grid,k); 
    if(temp!=LLONG_MAX) 
    down=grid[i][j]+temp; 
     
    } 
    } 
 
    else{ 
 
        if(i-1>=0){  //up 
 
            if(direction==4){ 
 
                long long temp=solve(i-1,j,4,grid,k); 
 
                if(temp!=LLONG_MAX) 
                up=grid[i][j]+temp; 
            } 
            else if(k){ 
                long long temp=solve(i-1,j,4,grid,k-1); 
                if(temp!=LLONG_MAX) 
                 up=grid[i][j]+temp; 
            } 
 
        } 
        if(i+1<n){  //down 
 
            if(direction==3){ 
                long long temp=solve(i+1,j,3,grid,k); 
                if(temp!=LLONG_MAX) 
                down=grid[i][j]+temp; 
            } 
            else if(k){ 
                long long temp=solve(i+1,j,3,grid,k-1); 
                if(temp!=LLONG_MAX) 
                down=grid[i][j]+temp; 
            } 
 
        } 
        if(j-1>=0){  //left 
 
            if(direction==2){ 
                long long temp=solve(i,j-1,2,grid,k); 
                if(temp!=LLONG_MAX) 
                left=grid[i][j]+temp; 
            } 
            else if(k){ 
                long long temp=solve(i,j-1,2,grid,k-1); 
                if(temp!=LLONG_MAX) 
                left=grid[i][j]+temp; 
            } 
 
        } 
        if(j+1<m){  //right 
 
            if(direction==1){ 
                long long temp=solve(i,j+1,1,grid,k); 
                if(temp!=LLONG_MAX) 
                right=grid[i][j]+temp; 
            } 
            else if(k){ 
                long long temp=solve(i,j+1,1,grid,k-1); 
                if(temp!=LLONG_MAX) 
                right=grid[i][j]+temp; 
            } 
        } 
    } 
 
    return dp[i][j][k][direction]=min({left,right,up,down}); 
 
} 
    int minCost(vector<vector<int>>& grid, int k) { 
        n=grid.size(),m=grid[0].size(); 

        memset(dp,-1,sizeof(dp));
        long long ans=solve(0,0,0,grid,k);
        if(ans==LLONG_MAX) return -1;
        return ans;
    } 
};

