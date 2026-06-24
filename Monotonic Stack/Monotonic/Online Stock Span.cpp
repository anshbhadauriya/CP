/*
prev greater ele find kro
*/
class StockSpanner {
public:
stack<pair<int,int>>st; //ele , kitna span hai

    StockSpanner() {
        
    }
    
    int next(int price) {
        int count=1;
        while(!st.empty() and st.top().first<=price){
             count+=st.top().second;
             st.pop();
        }

        st.push({price,count});

        return count;
        
    }
};

