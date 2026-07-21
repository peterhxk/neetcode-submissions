class TrieNode{
public:
    vector<TrieNode*> children{26};
    bool is_word;
    //char val; // for debug
    TrieNode(){
        for (int i = 0; i<26; i++){
            children[i] = nullptr;
        }
        is_word = false;
    }   
};

class WordDictionary {
private:
    TrieNode* head;
public:
    WordDictionary() {
        head = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = head;
        for (char c : word){
            if (cur->children[c-'a']==nullptr){
                cur->children[c-'a']=new TrieNode();
            }
            cur = cur->children[c-'a'];
            //cur->val = c;
            //cout << cur->val << ' '<<c<<endl;
        }
        cur->is_word=true;
    }
    
    bool search(string word) {
        queue<TrieNode*> q;
        q.push(head);
        for (int i = 0; i<word.size(); i++){
            char c = word[i];
            //cout<<c<<endl;
            int l = q.size();
            for (int x = 0; x<l;x++){
                TrieNode* cur = q.front();
                //cout<<"val: "<<cur->val<<endl;
                q.pop();
                if (c == '.'){
                    for (TrieNode* child : cur->children){
                        if (child != nullptr){
                            q.push(child);
                        }
                    }
                }
                else{
                    TrieNode* child = cur->children[c-'a'];
                    if (child != nullptr){
                        q.push(child);
                    }
                }
            }
        }
        cout << q.empty()<<endl;
        while (!q.empty()){
            TrieNode* final = q.front();
            q.pop();
            //cout << final->val << endl;
            if (final->is_word == true){
                return true;
            }
        }
        return false;
        
    }
};
