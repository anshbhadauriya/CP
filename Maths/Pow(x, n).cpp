class Solution {
public:
/*
key observation is->

2power8 == ((2)power2) power4== 4power4
so it means
2power8 == 4power4

so keep making it half to avoid TLE and keep multiplying (make it in long long to prevent from over flow)
TC and SC = O(log n)
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


Iterative->

    class Solution {
public:
    double myPow(double x, int n) {


        //abh iterative version

        long long N=n;
        double X=x;
        double ans=1;

        if(N<0){

            X=1/X;
            N=-N;

        }

        

        while(N>0){


            if(N%2==1){  //jab N yani power odd ho tabhi ans me multiply kro 
                ans*=X;
            }

            cout<<"current X is "<<X<<endl;
            cout<<"current N is "<<N<<endl;

            N=N/2;
            X=X*X;

            
        }

      

       
        return ans;
        
    }
};

