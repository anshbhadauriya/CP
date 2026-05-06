void storePrimes(int n){   //seive algo

    primes[0]=false;
    primes[1]=false;


    for(int i=2;i*i<n;i++){   //root n tak jao

    if(primes[i]){   //i ke divisble sare numbers ko not prime mark krdo bcs they are divisible by i

        for(int j=i*i;j<n;j+=i){
            
            primes[j]=false;
        }

    }

    }

    //i hope uk using template isnt cheating 

}
