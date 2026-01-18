class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        

        vector<int>result{-1,-1};

        int max_qf=INT_MIN;

        for(auto &x:towers){

            int x1=x[0],y1=x[1],qf=x[2];

            int distance=abs(x1-center[0])+abs(y1-center[1]);

            if(radius>=distance){


                if(qf>max_qf){

                    result[0]=x1;
                    result[1]=y1;
                    max_qf=qf;

                }
                if(qf==max_qf){

                    if(x1<result[0] and y1<result[0]){
                    result[0]=x1;
                    result[1]=y1;
                    max_qf=qf;

                    }
                }



            }

        }
        return result;
    }
};


class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {

        unordered_set<int>st;

       for(int i=0;i<nums.size();i++){
           if(nums[i]!=target[i]) st.insert(nums[i]);
       }
        return st.size();
        
    }
};


