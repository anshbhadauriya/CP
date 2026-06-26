class Solution {
public:
/*
koko can decide speed

har ghante vo k banana khata hai

so minimum speed find krni hai taki time pr banana khaa ske

*/
    int minEatingSpeed(vector<int>& piles, int h) {

        int l=1,high=*max_element(piles.begin(),piles.end()),n=piles.size(),ans=-1;

        while(l<=high){

            int mid=l+(high-l)/2;

            int k=mid;

            int hours=0;

            for(int i=0;i<n;i++){

                int time_for_curr_pile=piles[i]/k;
                if(piles[i]%k!=0) time_for_curr_pile++;

                hours+=time_for_curr_pile;

                if(hours>h) break;                
            }

            if(hours<=h){  //safe time
                ans=k;
                high=mid-1;  //khane ke speed aur kam kreke dekho
            }
            else{  //speed badao
                l=mid+1;
            }
        }

        return ans;        
    }
};

/*
TC-> O(log max(piles)) and each time iterated all ele to find time O(n)

so TC is O(n log max(piles))

SC -> O(1)
*/
