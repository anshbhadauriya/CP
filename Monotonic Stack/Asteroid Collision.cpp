/*
agr +ve hai too right
-ve too left

if 2 aestroids meet so smaller will be destroyed
if size is same so both will be destroyed

sirf 1 hi case me collide hoga 

+ve ele and then -ve ele (right and left)

*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();

        vector<int>ans;
        stack<int>st;
        for(int i=0;i<n;i++){

            if(!st.empty() and st.top()>=0 and asteroids[i]<0 and st.top()==abs(asteroids[i])){ st.pop(); continue; }

            while(!st.empty() and st.top()>=0 and asteroids[i]<0 and abs(asteroids[i])>st.top()) st.pop();

            if(!st.empty() and st.top()>=0 and asteroids[i]<0 and st.top()>abs(asteroids[i])){  continue; }

            if(!st.empty() and st.top()>=0 and asteroids[i]<0 and st.top()==abs(asteroids[i])){ st.pop(); continue; }

           // cout<<asteroids[i]<<" ";

            st.push(asteroids[i]);
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;




        
    }
};
