/*
agr number 1 hua yaa perfect square too alice jeetegi


agr koi number hai 50

so alice isse pehle 1 remove kregi too 49 bnega and bob will win

so alice agr 4 remove kre too 46 bnega so 46 isnt perfect sqr so bob will remove 1

so greedy wont work here

try dp

so dp[n][turn]

dp[n][turn] represnt out come of state with present turn of player

 dp[n][0] -> Alice outcome when n stones remain
 dp[n][1] -> Bob outcome when n stones remain

*/
class Solution {
public:

vector<vector<int>>dp;

bool solve(int n,int turn){

    if(n==0){

        if(turn==0) return dp[n][turn]=false; //agr n khtm hogya aur turn alice ki hai
        else  return dp[n][turn]=true;  //n khtm aur turn bob ki
    }

    if(dp[n][turn]!=-1) return dp[n][turn];

    if(turn==0){  //agr alice ki turn hai
    for(int i=1;i*i<=n;i++){

        if(solve(n-(i*i),1)==true) return dp[n][turn]=true;

    }

    return dp[n][turn]=false; //agr koi aissa move nhi hai jisse alice jeete

    }

    else if(turn==1){ //agr bob ki turn hai

    for(int i=1;i*i<=n;i++){

        if(solve(n-(i*i),0)==false) return dp[n][turn]=false; //agr minus krne se bob jeet rha so choose it
    }

    return dp[n][turn]=true; //agr aissa koi move nhi jisse bob jeete too return true 


    }

    return dp[n][turn]=false; //true ya false kuch bhi return krdo idhr 

}

    bool winnerSquareGame(int n) {

        dp.resize(n+1,vector<int>(2,-1));

        return solve(n,0);
        
    }
};