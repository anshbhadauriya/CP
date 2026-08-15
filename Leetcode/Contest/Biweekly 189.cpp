Q1->
  class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {

        int ans=0;
        ans+=requests.front();
        for(int i=0;i<requests.size()-1;i++){
            

            ans+=abs(requests[i]-requests[i+1]);
        } 

        return ans;
        
    }
};
Q2->
  /*
yaa too left most and right most ko same banao

yaa too rotate

aaaabbaa
ababbaca

forcefully palindrome banao

fir left shift kro 

check min operations
*/
class Solution {
public:
    int minOperations(string s) {

        deque<char>dq(s.begin(),s.end());

        int n=dq.size();

        int minimum=INT_MAX;

       

        for(int i=0;i<n;i++){

            //abh palindrome banao

            int operations=0,l=0,h=n-1;
            while(l<h){

                if(dq[l]!=dq[h]){

                    int diff1=abs((dq[l]-'a')-(dq[h]-'a'));

                    int diff2=(25-max(dq[l]-'a',dq[h]-'a'))+min((dq[l]-'a'),(dq[h]-'a'))+1; //z ke baad se  bana kr dekho
                    // cout<<diff1<<" "<<diff2<<endl;

                    // cout<<(25-(max(s[l]-'a',s[h]-'a')))<<endl;

                    operations+=min(diff1,diff2);

                    // cout<<diff1<<" "<<diff2<<endl;

                    
                    
                }
                l++;
                h--;
            }

            minimum=min(minimum,operations+i);

            //left rotate kro

            dq.push_back(dq.front());
            dq.pop_front();
            
        }

        return minimum;

        

        
        
    }
};
