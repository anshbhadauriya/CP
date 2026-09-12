Q1->
  /*
past wale curr ele ka idx save kro
*/
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {

        unordered_map<int,vector<int>>mp;

        for(int i=0;i<nums.size();i++){

            mp[nums[i]].push_back(i);

        }

        int count=0;

        //now check kiske freq 3 hai 

        for(auto x:mp){

            auto &curr=x.second;
            if(curr.size()==3){

                if(curr[1]-curr[0]==curr[2]-curr[1]) count++;
            }
        }

        return count;
        
    }
};

Q2->
  /*
past wale curr ele ka idx save kro
*/
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {

        unordered_map<int,vector<int>>mp;

        for(int i=0;i<nums.size();i++){

            mp[nums[i]].push_back(i);

        }

        int count=0;

        //now check kiske freq 3 hai 

        for(auto x:mp){

            auto &curr=x.second;

            if(curr.size()>2){

                int diff=curr[1]-curr[0];
                bool inValid=false;
                
                for(int i=1;i<curr.size()-1;i++){
                    if(curr[i+1]-curr[i]!=diff){
                        inValid=true;
                        break;
                    }
                }

                if(!inValid) count++;
                
            }
        }

        return count;
        
    }
};
