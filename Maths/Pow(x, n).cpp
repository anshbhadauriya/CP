class Solution {
public:
/*
key observation is->

2power8 == ((2)power2) power4== 4power4
so it means
2power8 == 4power4

so keep making it half to avoid TLE and keep multiplying (make it in long long to prevent from over flow)
*/

double solve(double x,long n){

    if(n==0) return 1;

    if(n<0){
        return 1/solve(x,-n);  //+ve bana do 
    }

    if(n%2==0){
        return solve(x*x,n/2);
    }
    else{

        return x*solve(x*x,(n-1)/2);
    }
}
    double myPow(double x, int n) {
        
       return solve(x,1L*n);
    }
};
