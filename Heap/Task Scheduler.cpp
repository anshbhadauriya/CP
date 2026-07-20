/*
task given hai A to Z

joo task sbse zyda aarha so try to execute that early
bcs agr last me usko choroge soo it will increase opeartions like this-> (A_A_A_A)

ek bar me n+1 task lo aur implement kro

curr ele + n other ele  == 1 cycle

btw hme ele se mtlb nhi bss uski freq se hai

*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int>mp(26,0);

        for(auto x:tasks) mp[x-'A']++;

        priority_queue<int>pq;

        for(auto x:mp){
            if(x>0) pq.push(x);
        }
        int time=0;
        while(!pq.empty()){

            vector<int>temp;

            for(int i=1;i<=n+1;i++){

                if(!pq.empty()){
                int freq=pq.top();
                pq.pop();
                
                freq--;  //ek ele sequence me dalo

                temp.push_back(freq);

                }
            }

            for(auto x:temp){
                if(x>0) pq.push(x);  //ho skta hai kisi ele ki freq 0 hogai so exclude that
            }

            if(pq.empty()){  //last ele the 
                time+=temp.size();
            }
            else time+=n+1;

        }

        return time;
        
    }
};
/*
TC-> O(n log 26) kyuki ek max 26 chars ho skte
    ==O(n)

SC-> pq.size() < 26 and mp size < 26 so O(1)
*/
