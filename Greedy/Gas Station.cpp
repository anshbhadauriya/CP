/*
gas[i] = gas you receive
cost[i] = gas needed to reach the next station

check prev submissions this one is most optimized 
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n=gas.size();

        //vector<int>extra(n);

        int total=0,curr=0,start=0;

        for(int i=0;i<n;i++){
            int extra=gas[i]-cost[i];
            total+=extra;
            //cout<<extra[i]<<" ";
            curr+=extra;
            if(curr<0){
                curr=0;
                start=i+1;
            }
        }

        if(total<0) return -1;

        return start;

        
    }
};