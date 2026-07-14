class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string>st(wordList.begin(),wordList.end());

        if(!st.count(endWord)) return 0;

        queue<pair<string,int>>q; //string , level

        q.push({beginWord,1});

        while(!q.empty()){

            string curr=q.front().first;
            int level=q.front().second;
            q.pop();

            if(curr==endWord) return level;


            for(int i=0;i<curr.size();i++){  //sare letters of curr word me jao

            string temp=curr;

            for(char j='a';j<='z';j++){  //try each alphabet

            temp[i]=j;

            if(st.count(temp)){
                q.push({temp,level+1});
                st.erase(temp);  //erase krdo too prevent loop
            }

            }


            }
        }

        return 0;
        
    }
};

/*
TC-> O(n*l^2*26)
SC-> O(n*l)
*/
