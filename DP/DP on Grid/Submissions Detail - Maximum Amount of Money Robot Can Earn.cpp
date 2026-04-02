class Solution {
public:
int n,m;
int solve(int i,int j,int neutral,vector<vector<int>>& coins, vector<vector<vector<int>>>&dp){

if(i==n-1 and j==m-1){  //base case

    if(coins[i][j]<0){  //agre -ve hai

    if(neutral<2){  //agr neutral bache hai too always use it for last cell
        return 0;  
    }
    else return coins[i][j];  //agr nhi bacha too return as it is 
    
    }
    
        return coins[i][j];  //agr +ve hai too return as it is
    
    
}

if(dp[i][j][neutral]!=INT_MIN) return dp[i][j][neutral];


int right=INT_MIN,down=INT_MIN;
//if +ve number
if(coins[i][j]>=0){

if(j+1<m){
    right=coins[i][j]+solve(i,j+1,neutral,coins,dp);
}

if(i+1<n){
    down=coins[i][j]+solve(i+1,j,neutral,coins,dp);
}

}

if(coins[i][j]<0){  //agr -ve aae

if(neutral<2){
if(j+1<m){   
int take_right=INT_MIN,skip_right=INT_MIN;
    take_right=coins[i][j]+solve(i,j+1,neutral,coins,dp); //skip neutral
    skip_right=solve(i,j+1,neutral+1,coins,dp);  //take neutral
    right=max(take_right,skip_right);

}

if(i+1<n){  
int take_down=INT_MIN,skip_down=INT_MIN;
    take_down=coins[i][j]+solve(i+1,j,neutral,coins,dp); //use neutral
    skip_down=solve(i+1,j,neutral+1,coins,dp);  //skip neutral
    down=max(take_down,skip_down);
}

}

else{
if(j+1<m){
    right=coins[i][j]+solve(i,j+1,neutral,coins,dp);
}

if(i+1<n){
    
    down=coins[i][j]+solve(i+1,j,neutral,coins,dp);
}


    
}
}
return dp[i][j][neutral]= max(right,down);


}
    int maximumAmount(vector<vector<int>>& coins) {
        n=coins.size(),m=coins[0].size();
    

//yaad rkho ki--> “If answer range includes negatives → NEVER use -1 for DP”
vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(3,INT_MIN)));

        return solve(0,0,0,coins,dp);
    }
};
