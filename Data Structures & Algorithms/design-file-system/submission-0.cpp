struct Node {
    unordered_map<string,Node*> children;
    int value;
};
class FileSystem {
public:
    Node* root = new Node();
    FileSystem() {
    }
    
    bool createPath(string path, int value) {
        if (path == "" || path == "/"){
            return false;
        }
        string cur;
        Node* cur_node = root;
        for (int i =1; i<path.size();i++){
            auto c = path[i];
            if (c != '/'){
                cur += c;
            } else {
                if (cur_node->children.contains(cur)){
                    cur_node = cur_node->children[cur];
                } else {
                    return false;
                }
            }
        }
        if (cur_node->children.contains(cur)){
            return false;
        }
        cur_node->children[cur] = new Node();
        cur_node->children[cur]->value = value;
        return true;

    }
    
    int get(string path) {
        if (path == "" || path == "/"){
            return -1;
        }
        string cur;
        Node* cur_node = root;
        for (int i =1; i<path.size();i++){
            auto c = path[i];
            if (c != '/'){
                cur += c;
            } else {
                if (cur_node->children.contains(cur)){
                    cur_node = cur_node->children[cur];
                } else {
                    return -1;
                }
            }
        }
        if (cur_node->children.contains(cur)){
            return cur_node->children[cur]->value;
        }
        return -1;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
