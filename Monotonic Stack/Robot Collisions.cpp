class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {

        //n -> 1 indexed robots 
        //each robot have position(unique), health, direction
        //sare robots sth me chle ek line pr ek sath ek speed pr in given directions
        //if 2 robots ever share the same position they will collide
        //if 2 robots collide so the robot with lower health removed from line aur other robot ki health -1 hojaegi
        //agr dono roobots ki health same hai aur collide kra hai too both are removed

        //return krna hai robots ki final health 

        vector<pair<int,pair<int,char>>>nums;  //position,{health,directions}

        for(int i=0;i<positions.size();i++){
            int a=positions[i];
            int b=healths[i];
            char c=directions[i];
            nums.push_back({a,{b,c}});
        }

        sort(nums.begin(),nums.end());

        vector<pair<int,pair<int,char>>>st;

        for(auto &x:nums){
            st.push_back(x);

            while(st.size()>1 and st.back().second.second=='L' and st[st.size()-2].second.second=='R'){
                if(st.back().second.first>st[st.size()-2].second.first){
                    st.back().second.first-=1;
                    auto temp=st.back();
                    st.pop_back();
                    st.pop_back();
                    st.push_back(temp);
                    continue;
                }
                else if(st.back().second.first<st[st.size()-2].second.first){
                    st[st.size()-2].second.first-=1;
                    st.pop_back();
                    continue;
                }
                else{
                    st.pop_back();
                    st.pop_back();
                    continue;
                }
            }
            
        }

        if(st.empty()) return {};

        unordered_map<int,int>mp;

        for(auto &x:st){
            int position=x.first;
            int health=x.second.first;
            mp[position]=health;
        }

        vector<int>ans;

        for(auto &x:positions){
            if(mp.count(x)){
                ans.push_back(mp[x]);
            }
        }

        return ans;
        
    }
};
