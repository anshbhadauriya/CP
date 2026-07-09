/*
n -> number of nodes (0 to n-1)

nums-> sorted increasing order

if |nums[i] - nums[j]| <= maxDiff  so there is undirected edge

queries tell that there is path bw u and v or not


*/


//DSU template 
class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);   // Path Compression
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        // Union by Size
        if (size[pu] < size[pv])
            swap(pu, pv);

        parent[pv] = pu;
        size[pu] += size[pv];
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU dsu(n);

                for(int i=0;i<n-1;i++){  

                if(abs(nums[i]-nums[i+1])<=maxDiff) dsu.unite(i,i+1);

                }

/* Sabhi pairs ko unite karne ki zaroorat nahi hai.
 Agar 0-1, 1-2, aur 2-3 connected hain,
 to DSU ke through 0 automatically 3 se bhi connected ho jayega.
 Isliye sirf adjacent indices ko unite karna kaafi hai.
 */            
            
        

        vector<bool>res;

        for(auto x:queries){
            int u=x[0],v=x[1];

            if(dsu.find(u)==dsu.find(v)) res.push_back(true);
            else res.push_back(false);
        }

        return res;
    }
};
