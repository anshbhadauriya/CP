class Solution {
public:
    int maxNumberOfBalloons(string text) {

        vector<int>mp(26,0);

        for(auto x:text){
            mp[x-'a']++;
        }
        int minimum=INT_MAX;

        string temp="balloon";
        for(auto x:temp){

            //cout<<x<<"-> "<<mp[x-'a']<<endl;
            if(x=='l' or x=='o'){
                if(mp[x-'a']<2) return 0;
                minimum=min(minimum,mp[x-'a']/2);

                continue;
            }
            minimum=min(minimum,mp[x-'a']);
        }

        return minimum;
        
    }
};
