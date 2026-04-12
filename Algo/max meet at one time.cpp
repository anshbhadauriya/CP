int maxPeople(vector<int>& entry, vector<int>& exit) {
    vector<pair<int, int>> events;

    int n = entry.size();

    for (int i = 0; i < n; i++) {
        events.push_back({entry[i], 1});   // person enters
        events.push_back({exit[i], -1});  // person leaves
    }

    sort(events.begin(), events.end());

    int curr = 0;
    int ans = 0;

    for (auto &e : events) {
        curr += e.second;
        ans = max(ans, curr);
    }

    return ans;
}
