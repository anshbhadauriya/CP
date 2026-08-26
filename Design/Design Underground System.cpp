class UndergroundSystem {
public:
unordered_map<int,pair<string,int>>customers;
unordered_map<string,pair<int,int>>mp;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {

        customers[id]={stationName,t};
        
    }
    
    void checkOut(int id, string stationName, int t) {
        
        auto it=customers[id];

        //customers.erase(id);

        int time_diff=t-it.second;

        string start=it.first;
        string temp=start+'#'+stationName;
        
        int old_time=mp[temp].first;
        int total_ele=mp[temp].second;

        mp[temp]={time_diff+old_time,total_ele+1};
        
    }
    
    double getAverageTime(string startStation, string endStation) {

        string temp=startStation+"#"+endStation;

        auto &it=mp[temp];

        return (it.first*1.0)/(it.second*1.0);
        
    }
};
