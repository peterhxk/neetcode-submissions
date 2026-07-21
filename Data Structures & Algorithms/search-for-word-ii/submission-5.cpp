class TrieNode{
public:
    vector<TrieNode*> children{26};
    string word;
    TrieNode(){
        for (int i = 0; i<26; i++){
            children[i]=nullptr;
        }
    }

};
class Solution {
    
public:
    TrieNode* root;
    unordered_set<string> ret;
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        string c = "";
        //cout<<words[0]<<" "<<to_string(board[0][0])<< (words[0]==to_string(board[0][0]));
        buildTrie(words);
        scanBoard(board);
        vector<string> r(ret.begin(),ret.end());
        return r;
    }   
    void buildTrie(vector<string>& words){
        for (string word : words){
            TrieNode* cur = root;
            for (char c : word){
                if (cur->children[c-'a']==nullptr){
                    cur->children[c-'a']= new TrieNode();
                }
                cur = cur->children[c-'a'];
            }
            cur->word = word;
        }
    }
    void dfs(vector<vector<char>>& b, int x, int y, TrieNode* node) {
        char c = b[x][y];
        if (c == '#' || !node->children[c-'a']) return;   // visited, or not in Trie
        node = node->children[c-'a'];

        if (!node->word.empty()) {
            ret.insert(node->word);                         // dedupe: report each word once
        }

        b[x][y] = '#';                                    // mark visited
        int dirs[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
        for (auto& d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (nx >= 0 && ny >= 0 && nx < (int)b.size() && ny < (int)b[0].size())
                dfs(b, nx, ny, node);
        }
        b[x][y] = c;                                      // unmark (backtrack)
    }
    void scanBoard(vector<vector<char>>& b){
        // unordered_set<string> visited;
        // checkPos(b, 3, 3, visited);
        for (int i = 0; i< b.size(); i++){
            for (int j = 0; j<b[0].size();j++){
                dfs(b, i, j, root);
            }
        }
    }

    
};
