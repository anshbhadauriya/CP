class Solution {
public:
vector<string>st;
void solve(int idx,string &tiles,string &curr){
    if(idx==tiles.size()){
        st.push_back(curr);
        return;
    }

    curr.push_back(tiles[idx]);
    solve(idx+1,tiles,curr);
    curr.pop_back();
    solve(idx+1,tiles,curr);
}
    int numTilePossibilities(string tiles) {
        int count=0;
        string curr="";
        solve(0,tiles,curr);

        for(auto x:st) cout<<x<<" ";
        set<string>result;
        
        for(int i=0;i<st.size();i++){
            
            string curr=st[i];
            if(curr.empty()) continue;
            
            sort(curr.begin(),curr.end());
            result.insert(curr);
            while(next_permutation(curr.begin(),curr.end())) result.insert(curr);
        }
        return result.size();
    }
};
