class Solution {
public:

using ll=long long;
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        
        /*
        
        nums is sorted

        Har idx ke lie closest(x) means -> abs(nums[x] - nums[y]) minimized

        it means closest find krne ke lie you'll have to check both side neighbours and do abs(nums[x] - nums[y]) choose minimum.

        har idx ke lie we have 2 choices to jump:

        kisi bhi idx me jump kro with cost-> abs(nums[x] - nums[y])

        or 

        closest(x) with cost-> 1


        so in closest array we will store adj idx with minimum cost

        ex->

        nums = [0,2,3,9]
  
        closest = [1, 2, 1, 2]   (all cost is 1 here)

        now we have to got from 3 to 0 idx

        agr closest wale me jaoge so cost is 1

        so we will go from idx 3->2 with cost 1 and then 2->1 with cost 1 

        but we cannot go from idx 1 to 0 same way bcs in closest at idx 1 we can go to idx 2 only for closest 

        so we'll choose diff way to go at 1 now 


        we will do direct jump so that cost is |2 - 0| = 2

        total=1+1+2=4

        do same process for all queries


        so i think we have to try to utilize closest array the most and try to go as far as we can with closest then go with direct jump


        but that point can give worse answer 



        so the idea is given nums is sorted in ascending

        so to move from point i to i+1 we have to check 

        a= if i+1 present in closest at ith idx

        b= normal jump cost 

        min(a,b) is the minimum way to reach at point i from i+1


        so jumping at one step will always fine bcs its sorted 

        it will never be like that jumping at i to random idx will give optimal

        so calculate prefix from 0 to i at each point

        it will tell the minimum cost to reach from point 0 to i 






        */


        int n=nums.size();

        //closest vector

        vector<ll>closest;

        cout<<"Closest-> ";

        for(int i=0;i<n;i++){

            if(i==0){ closest.push_back(1); cout<<closest[i]<<" ";  continue; }//always fixed
            if(i==n-1){ closest.push_back(n-2); cout<<closest[i]<<" ";  continue; }//always fixed

            ll l=abs(nums[i]-nums[i-1])*1LL;
            ll r=abs(nums[i]-nums[i+1])*1LL;

            if(l<=r){

                closest.push_back(i-1);
            }
            else closest.push_back(i+1);

            cout<<closest[i]<<" ";


        }

        cout<<endl;


        //build prefix

        vector<ll>pref;

        //abh sab smjh aagyaa

        // cout<<"pref-> ";

        for(int i=0;i<n;i++){
            if(i==0){
                pref.push_back(0);
                cout<<pref[i]<<" ";
                continue;
            }


            if(closest[i-1]==i){  //agr closest me present ho
 
                int last=pref.back();

                pref.push_back((last+1)*1LL);
            }

            else{  //direct jump

            ll direct_jump_cost=abs(nums[i-1]-nums[i]);

            pref.push_back((pref.back()+direct_jump_cost)*1LL);

            }

            // cout<<pref[i]<<" ";
        }
        // cout<<endl;



        //pref is correct

        //now suff


        vector<ll>suff(n,0);

        // cout<<"suff-> ";

        for(int i=n-2;i>=0;i--){

            if(closest[i+1]==i){
                suff[i]=suff[i+1]+1;
            }

            else{

                ll direct_jump_cost=abs(nums[i+1]-nums[i]);

                suff[i]=suff[i+1]+direct_jump_cost;

            }

            // cout<<suff[i]<<" ";
        }

        // for(auto x:suff) cout<<x<<" ";

        // cout<<endl;



        //suff done


        //now queries

        vector<int>ans;

        for(auto x:queries){

            int l=x[0];
            int r=x[1];

            if(l<=r){  //use prefix

            ans.push_back(pref[r]-pref[l]);

            }

            else{

                ans.push_back(suff[r]-suff[l]);
            }

            // cout<<ans.back()<<" ";
        }

        //INT over flow :)

        //DONEEEE!




        return ans;
    }
};
