class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth=0;
        vector<int>res;
        for(auto &c : seq)
            if (c == '(') {
                ++depth;
                res.push_back(depth % 2);
            } else {
                res.push_back(depth % 2);
                --depth;
            }
        return res;
    }
};
