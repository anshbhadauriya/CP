class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> dead(deadends.begin(), deadends.end());

        queue<pair<string, int>> q;

        q.push({"0000", 0});

        unordered_set<string> visited;

        while (!q.empty()) {
            int n = q.size();

            
                string curr = q.front().first;

                int moves = q.front().second;

                q.pop();

                if (curr == target)
                    return moves;

                if (dead.count(curr))
                    continue;

                if (visited.count(curr))
                    continue;

                visited.insert(curr);

                for (int i = 0; i < 4; i++) {
                    string temp1 = curr;
                    string temp2 = curr;

                    int digit = curr[i] - '0';
                    digit = (digit + 1) % 10;
                    temp1[i] = digit + '0';
                    q.push({temp1, moves + 1});

                    digit = curr[i] - '0';
                    digit = (digit - 1 +10) % 10;
                    temp2[i] = digit+'0';
                    q.push({temp2, moves + 1});
                }
            
        }
        return -1;
    }
};
