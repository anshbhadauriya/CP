Q1->
  class Solution {
public:
    bool check(int x){
        if(x==0) return true;
        unordered_set<int>st;
        int num=x;
        string binary;
        while(num>0){
            int rem=num%2;
            st.insert(rem);
            binary=to_string(rem)+binary;
            num=num/2;
        }
        if(st.size()==1) return  true;
        return false;
    }
    int countMonobit(int n) {
        int count=0;
        for(int i=0;i<=n;i++){
            if(check(i)){
                count++;
            }
            
        }
        return count;
    }
};

Q2->
  class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(nums.front(),nums.back());
        

        //logic is : 
        //alice ki first chance hai too vo hmesha maximum result lane ke lie yaaa too sirf left se remove kr skti hai continuously yaa to right se continuously
        //agr alice biche se koi remove krti hai too bob hmesha alice ka maximum result hata dega agr bob ko chance mil gai

        //too kuch aissa kro ki bob ko chance hi na mile

        //kyuki agr bob ko chance mili too bob alice ko best answer nhi mil pagea

        //so remove all elements and leave only 1, either from all left or all from right
        //so that bob cant do anything
        //thats why answer is max of front or back
    }
};

Q3->
  class RideSharingSystem {
public:
    deque<int>rider;
    deque<int>driver;
    unordered_set<int>st;
    
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push_back(riderId);
        
        
    }
    
    void addDriver(int driverId) {
        driver.push_back(driverId);
        
    }
    
    vector<int> matchDriverWithRider() {
        while(st.count(rider.front())) rider.pop_front();
        if(driver.empty() or rider.empty()) return {-1,-1};
        int d_id=driver.front();
        driver.pop_front();
        int r_id=rider.front();
        rider.pop_front();
        
        return {d_id,r_id};
        
    }
    
    void cancelRider(int riderId) {
        if(find(rider.begin(),rider.end(),riderId)!=rider.end()){
        st.insert(riderId);
        }
        
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */
