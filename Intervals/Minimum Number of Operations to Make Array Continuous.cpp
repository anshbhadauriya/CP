/*
sare ele unique banao
max aur min ele ka diff == size-1
so basically continuous form me numbers hone chaiye
koi number skip nhi hona chaiye

first find ki kis part ko select kre longest consecutive banane me

for example 1 5 6 7 8

idhr instead of making it 1 2 3 4 5 make it like 9 5 6 7 8


now lets take example 
1 50 51 52 100

here just make 1 as 49 and 100 as 53 so sequnce will be 49 50 51 52 53
or just make 1 as 53 and 100 as 54 
both are valid
so basically hame yeh pta krna hai ki kis interval of size 5 most elemennts gets fit in

jaise iss case me agr interval ho 49 to 53 so we know ki isske andr 50 51 52 aaajaege
so we will only need to change 2 elements 1 and 100


so if min is 1 and max is 100 in given array so and we know the array size is 5
now find all intervals of size 5 from 1 to 100 : example->

1-5
5-10
11-15
16-20
21-25
upto 100
and find in which intervals most ele gets fit in

aur haan duplicates remove kr dena bcs duplicates ek hi interval me fit hojaega sb which will give wrong answer (agr iss cheez me confusion ho so try this tc [8,5,9,9,8,4])

okay now code worked but TLE aagya as expected bcs we are checking for each interval

so instead of checking each interval

we can start each interval by which our value is starting
for example 1 50 51 52 100

isme agr sirf 
1-5
50-54
51-54
52-56
100-104

then it will work same just think logically



*/
class Solution {
public:
    int minOperations(vector<int>& nums) {

        int n=nums.size();

       

        //remove duplicates and sort

        set<int>st(nums.begin(),nums.end());

        nums.clear();

        for(auto x:st) nums.push_back(x);



        int minimum=nums.front();
        int maximum=nums.back();

        // int l=minimum;
        // int h=minimum+n-1;
        int max_fit_in=0;
        int i=0;
        while(i<nums.size()){

            int l=nums[i];
            int h=l+n-1;
            //now find out how many ele fits in curr interval

            // int left=lower_bound(nums.begin(),nums.end(),l)-nums.begin();
            //l pehle se hi interval ke shuru me hai so we dont need to find left
            int left=i;
            int right=upper_bound(nums.begin(),nums.end(),h)-nums.begin();

            int ele_fits_in=right-left;

            max_fit_in=max(max_fit_in,ele_fits_in);

            // if(max_fit_in==ele_fits_in){
            //     cout<<l<<" "<<h<<endl;
            // }
            
            i++;
        }

        return n-max_fit_in;


        
    }
};
/*
TC-> O(n log n)   // set
+ O(n)       // copy
+ O(n log n) // upper_bound for every unique element
soo O(n log n)
SC-> O(n)
*/
