class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int minimum=prices[0],maximum=0;
     for(int i=1;i<prices.size();i++){
        int diff=prices[i]-minimum;
        maximum=max(maximum,diff);

        minimum=min(minimum,prices[i]);
     }
     return maximum;   
    }
};