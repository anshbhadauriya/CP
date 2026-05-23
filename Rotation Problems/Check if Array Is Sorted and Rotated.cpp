class Solution {
public:
    bool check(vector<int>& nums) {

        /*
        shuru me ascending order me tha array

        kuch ele rotate krdie


        
        Agr sirf ek drop ho too yes

        drop mtlb ascending order me kitne non ascending me h

        so basically we need to check ki

        kya ham array ko rotate krke sort kr skte hai

        rotate means front se ele nikalo aur back me dalo

        */

        // agr kisi ele ke ange piche usse bada ele hai so its always false

        int drops=0;

        int n=nums.size();

        // if(n>=3 and nums[0]>nums[1] and nums[0]<nums[n-1]) return false;  //test case 2


        // for(int i=0;i<n-1;i++){
        //     if(nums[i]>nums[i+1]) drops++;
        // }

        int drops2=0;

        for(int i=0;i<n;i++){

            int mid=nums[i];

            int left=(i-1>=0)?nums[i-1]:nums.back();

            int right=(i+1<n)?nums[i+1]:nums.front();

            if(mid<=right and mid>=left){
                continue;
            }

            else if(mid>=right and mid>=left) drops2++;
            
            else drops++;
                
        }

        //right se chota hona chaiye

        //left se bada

        // 1 ,2, 4 ,4,2,4 

        //2 , 1 , 3 , 4

        //  4 ,2 , 1, 3



        cout<<drops<<endl;

        if(drops<=1) return true;

        return false;

        


        
    }
};