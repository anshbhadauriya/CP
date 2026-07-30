class Solution {
public:
int n,m;

struct TrieNode{  //trie data structure banao

    bool endOfWord;
    string word;
    TrieNode* children[26];

};

TrieNode* getNode(){

    TrieNode* newNode= new TrieNode();
    newNode->endOfWord=false;  //shuru me we cannot say ki word end hogya 
    newNode->word="";

    for(int i=0;i<26;i++){
        newNode->children[i]=NULL;
    }

    return newNode;

}

void insert(TrieNode* root,string &word){

    TrieNode* crawler=root; //crawler jakr check krega ki kya current word hai trie me

    //pehle root me check krega ki starting word hai kya string ka.. agr nhi hai too insert all words one after one

    for(int i=0;i<word.size();i++){

        char curr=word[i];
        
        if(crawler->children[curr-'a']==NULL){ //if nhi hai 

        crawler->children[curr-'a']=getNode();
        }

        crawler=crawler->children[curr-'a'];
    }

    crawler->endOfWord=true;
    crawler->word=word;
}

vector<string> ans;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {

    char ch=board[i][j];

    //agr ye cell pehle hi visit ho chuka hai ya
    //trie me current character exist hi nhi karta
    if(ch == '#' or node->children[ch - 'a'] == NULL)
        return;

    //trie me current character wale node pr move kro
    node = node->children[ch - 'a'];

    //agr yaha koi word end ho rha hai to answer me add krdo
    if(node->endOfWord) {

        ans.push_back(node->word);

        //duplicate answer na aaye isliye false kr diya
        node->endOfWord = false;
    }

    //current cell ko visited mark krdo
    board[i][j]='#';

    //explore in all 4 directions
    for(int k=0;k<4;k++) {

        int ni = i+dx[k];
        int nj = j+dy[k];

        if (ni >= 0 and ni < n and nj >= 0 and nj < m) {
            dfs(board,ni,nj,node);
        }
    }

    //backtracking(original character wapas rkh do)
    board[i][j] = ch;
}




    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        n=board.size();
        m=board[0].size();

        TrieNode* root=getNode();

        for(auto &word:words) {
            insert(root, word);
        }

         for(int i=0;i<n;i++) {

            for(int j=0;j<m;j++) {

            dfs(board, i, j, root);
            }
            }

        return ans;


    }
};
/*
without a Trie for every word you would search the whole board
with a Trie you traverse the board once searching for all words simultaneously
*/