/*

so hame har ele ki 0th bit 1st bit 2nd bit and so on check krna pdega

so agr 0th bit me 0 ke count%3!=0 hai too mtlb jo bhi single ele hoga uski 0th bit 0 hogi
aur agr 1 count%3!=0 so single ele ki 0th bit 1 hogi

so like this check for all 32 bits

to check kth bit of a number is 0 or 1:

if(num & (1 << k))==0)  so kth bit was 0
else kth bit was 1

proof- 


aur agr kabhi kth bit ko 1 krna ho so we can do it like:

answer=(answer | (1<<k) );  basically ham kth bit ko 1 se or krva rhe taki vo bit 1 hojae like this: 
0000
0001
------
0001


so hme sare bit dekhna hoga 
agr kth bit sare numbers ke 3 se divisible h mtlb that is fine but agr 3 se divisible nhi h so ismme problem h
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int answer=0;

        for(int k=0;k<=31;k++){

            int temp=(1<<k);  //left shift

            int zeroCount=0,oneCount=0;

            for(auto curr:nums){  //sare ele ke kth bit

            if((curr & temp)!=0){  //kth bit is one
            oneCount++;
            }
            else zeroCount++;
            }

            if(oneCount%3==1){  //mtlb single ele ki kth bit 1 hai so answer ke bhi kth bit one hogi

            answer=(answer | temp);  //kth bit ko 1 krdo
            }

        }

        return answer;
        
    }
};