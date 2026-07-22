class TimeMap {
public:
static bool cmp(int t, const pair<int, string>& p) {
    return t < p.first;
}
unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {

        mp[key].push_back({timestamp,value});
        
    }
    
    string get(string key, int timestamp) {

        if(!mp.count(key)) return "";

        auto &curr=mp[key];

        int idx=upper_bound(curr.begin(),curr.end(),timestamp,cmp)-curr.begin();

        if(idx==0) return "";

        return curr[idx-1].second;


    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
