class PrefixNode{
public:
    unordered_map<char, PrefixNode*> children;
    bool is_word;
    PrefixNode(){
        for (int i = 0; i<26; i++){
            children[i]=nullptr;
        }
        is_word = false;
    }
};

class PrefixTree {
    PrefixNode* head;
public:
    PrefixTree() {
        head = new PrefixNode();
    }
    
    void insert(string word) {
        PrefixNode* cur = head;
        for (char c : word){
            int i= c-'a';
            if (cur->children[i] == nullptr){
                cur->children[i] = new PrefixNode();
            }
            cur = cur->children[i];
        }
        cur->is_word = true;
    }
    
    bool search(string word) {
        PrefixNode* cur = head;
        for (char c : word){
            int i= c-'a';
            if (cur->children[i]==nullptr){
                return false;
            }
            cur = cur->children[i];
        }
        return cur->is_word;
        
    }
    
    bool startsWith(string prefix) {
        PrefixNode* cur = head;
        for (char c : prefix){
            int i= c-'a';
            if (cur->children[i]==nullptr){
                return false;
            }
            cur = cur->children[i];
        }
        return true;
    }
};
