class DSU {
public:


//stability = minimum edge strength in the spanning tree
        //maximize(minimum edge strength)
        //We want the weakest edge to be as strong as possible

        //too socho ki
        //Can we build a spanning tree where every edge has strength ≥ X ?
        //try kro X ko increase krne kaa...so baiscally we have to use binary searchh
        
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find (int x) {
        if (x == parent[x]) 
            return x;

        return parent[x] = find(parent[x]);
    }

    bool Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return false;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }

        return true;
    }
};

class Solution {
public:

    bool check(int n, vector<vector<int>>& edges, int k, int mid) {
        DSU dsu(n);

        vector<vector<int>> upgradeCandidates;

        for(auto &edge : edges) { 
            int u = edge[0];
            int v = edge[1];

            int s = edge[2];
            int m = edge[3];

            if(m == 1) {
                if(s < mid) {
                    return false;
                }

                dsu.Union(u, v); 
            } else {
                if(s >= mid) {
                    //no need to upgrade
                    dsu.Union(u, v);
                } else if(2*s >= mid) {
                    upgradeCandidates.push_back({u, v});
                }
            }
        }

        for(auto &edge : upgradeCandidates) { 
            int u = edge[0];
            int v = edge[1];

            if(dsu.find(u) != dsu.find(v)) {
                if(k <= 0)
                    return false;
                
                dsu.Union(u, v);
                k--; //upgrade
            }
        }


        int root = dsu.find(0);
        for(int node = 1; node <= n-1; node++) { 
            if(dsu.find(node) != root)
                return false;
        }
        return true;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        DSU dsu(n);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int s = edge[2];
            int m = edge[3];

            if(m == 1) { //must be included in the spanning tree
                if(dsu.find(u) == dsu.find(v))
                    return -1;
                
                dsu.Union(u, v);
            }
        }


        int result = -1;
        int l = 1;
        int r = 2*1e5;

     
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(check(n, edges, k, mid)) {
                result = mid;
                l = mid+1;
            } else {
                r = mid -1;
            }
        }

        return result;
    }
};
