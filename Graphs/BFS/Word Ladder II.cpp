//gives mle in leetcode but works in gfg
class Solution {
  public:
    vector<vector<string>> findSequences(vector<string> &wordList , string &beginWord, string &endWord) {
        
         
        unordered_set<string> st(wordList.begin(), wordList.end());

        vector<string> used_on_prev_level;
        used_on_prev_level.push_back(beginWord);

        queue<vector<string>> q;

        vector<vector<string>> ans;

        int level = 0;

        q.push({beginWord});

        while(!q.empty()) {

            auto curr_path = q.front();
            q.pop();

            // Previous level ke saare used words remove krdo
            if(curr_path.size() > level) {

                for(auto &x : used_on_prev_level)
                    st.erase(x);

                used_on_prev_level.clear();

                level++;
            }

            // Shortest level cross ho chuka hai
            if(!ans.empty() && curr_path.size() > ans[0].size())
                break;

            string word = curr_path.back();

            if(word == endWord) {

                // First path is obviously a shortest path
                if(ans.empty())
                    ans.push_back(curr_path);

                // Store other paths of same shortest length
                else if(curr_path.size() == ans[0].size())
                    ans.push_back(curr_path);
            }

            for(int i = 0; i < word.size(); i++) {

                char original = word[i];

                for(char j = 'a'; j <= 'z'; j++) {

                    word[i] = j;

                    if(st.count(word)) {

                        curr_path.push_back(word);

                        q.push(curr_path);

                        used_on_prev_level.push_back(word);

                        curr_path.pop_back();
                    }
                }

                // Restore original character
                word[i] = original;
            }
        }

        return ans;
        
    }
};
