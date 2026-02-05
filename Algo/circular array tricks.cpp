Kabhi bhi circulary array ho too har bar yeh nhi krna ki agr i=nums.size() too i=0 
yaa fir i=0 so i=nums.size()-1 

  instead do this-->
int safeindex(int i , int n){
    if(i<0)return n-1;
    return i%n;
}


if you want to access i+nums[i]th index element and when nums[i] can be negative means negative index handling=>
  result[i]= nums[((i+nums[i])%n+n)%n];
