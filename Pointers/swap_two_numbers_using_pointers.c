#include<stdio.h>


void swap(int *add_of_a,int *add_of_b){


    int temp=*add_of_a;  //value of a 

    *add_of_a=*add_of_b;

    *add_of_b=temp;




    

}

int main(){

    int a = 5;

    int b=10;

    // int* address_of_a=&a;
    // int* address_of_b=&b;

    printf("Before swap a is %d and b is %d",a,b);

    printf("\n");

    swap(&a,&b); //a aur b ka address bheja hai ... yaha par address_of_a aur address_of_b bhi bhej skte the

    printf("After swap a is %d and b is %d",a,b);  

    return 0;
}