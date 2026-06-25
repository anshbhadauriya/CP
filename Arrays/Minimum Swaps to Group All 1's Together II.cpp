class Solution {
public:

/*
pehle total 1's count krlo 

jitna bhi count aae mtlb utne 1 sth me rkhne hai

so har count size ki sliding window move krao aur har window me check kro ki kya sare 1's 
banane me kitne swap lgege ... in  easy words agr window 4 size ki hai aur hamari window me 
2 one hai too mtlb 2 swap ki aur need hai

too aisse hi window move krte rho aur check ki kis window me minimum swap required hai

and for circular condition u can just append same array at back

*/
    int minSwaps(vector<int>& nums) {

        int n=nums.size();

        int count=0;

        for(auto &x:nums) if(x==1) count++;

        cout<<"window size is "<<count<<endl;

        for(int i=0;i<n;i++) nums.push_back(nums[i]);
        

        //check first window

        int l=0,h=0,temp=0,minimum=INT_MAX;

        for(h=0;h<count;h++){

            if(nums[h]==1) temp++;
        }
        cout<<"h is "<<h<<endl;
        cout<<"l is "<<l<<endl;

        minimum=min(minimum,count-temp);


        while(h<nums.size()){

            if(nums[l]==1) temp--;
            l++;

            if(nums[h]==1) temp++;

            minimum=min(minimum,count-temp);

            h++;
        }


        return minimum;

        
    }
};

/*

TC-> O(n)
SC-> O(n) bcs n more ele added
*/
