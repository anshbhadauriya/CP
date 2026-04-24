class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {

        int l=0,r=0,d=0;

        for(auto x:moves){
            if(x=='L') l++;
            else if(x=='R') r++;
            else d++;
        }

        int maximum=max(l,r);
        maximum+=d;

        return maximum-min(l,r);
        
    }
};
