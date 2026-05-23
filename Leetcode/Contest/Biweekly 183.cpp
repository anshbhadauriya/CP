class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        /*
        
        x aur y 

        har even idx k lie nums[i]%k==x 
        har odd idx k lie nums[i]%k==y

        k kuch bhi rem ek bar odd aaega ek bar even

        
        */

        //pehle odd even

        int n=nums.size();

        int minCost=INT_MAX;


        for(int i=0;i<k;i++){

            for(int j=0;j<k;j++){

                if(i==j) continue;

                int curr_cost=0;

                for(int q=0;q<n;q++){

                    int rem=nums[q]%k;
                    int target;

                  if(q%2==0){

                      target=i;
                  }
                    else target=j;

                    int dist=abs(rem-target);

                    curr_cost+=min(dist,k-dist);
                }

                minCost=min(minCost,curr_cost);
            }
        }

        return minCost;
        
    }
};
