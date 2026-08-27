class SeatManager {
public:
priority_queue<int,vector<int>,greater<int>>pq;
int smallest=1;
    SeatManager(int n) {
        
    }
    
    int reserve() {

        if(!pq.empty()){

            int ele=pq.top();
            pq.pop();

            return ele;
        }

        return smallest++;
        
    }
    
    void unreserve(int seatNumber) {
        if(seatNumber<smallest) pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
