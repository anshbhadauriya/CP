class Router {
public:

deque<vector<int>>dq; //{s,d,t}
unordered_map<int,vector<int>>mp; //destination-> timestamp
set<vector<int>>st; //to track duplicates
unordered_map<int,int>pointer; //lazy deletion
int max_size;

    Router(int memoryLimit) {
        max_size=memoryLimit;
        
    }
    
    bool addPacket(int source, int destination, int timestamp) {

        if(st.count({source,destination,timestamp})){
            return false;
        }
        dq.push_back({source,destination,timestamp});
        mp[destination].push_back(timestamp);
        st.insert({source,destination,timestamp});

        if(dq.size()>max_size){
            auto x=dq.front();
            dq.pop_front();
            st.erase(x);
            pointer[x[1]]++;
        }
        return true;
    }
    
    vector<int> forwardPacket() {
        if(dq.empty()) return {};
        auto x=dq.front();

        dq.pop_front();

        st.erase(x);

        pointer[x[1]]++;

        return x;
    
    }
    
    int getCount(int destination, int startTime, int endTime) {

        auto &curr=mp[destination];
        int temp=pointer[destination];

        int l=lower_bound(curr.begin()+temp,curr.end(),startTime)-curr.begin();

        int r=upper_bound(curr.begin()+temp,curr.end(),endTime)-curr.begin();


        return r-l;




        
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */