class Node{
public:
    Node* parent;
    string cur;
    unordered_set<Node*> children;
    Node(string val){
        parent = this;
        cur = val;
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, Node*> m;
        for (auto account : accounts){
            Node* parent;
            for (int i = 0; i<account.size();i++){
                if (i==0){
                    parent = new Node(account[i]);
                }
                else{
                    if (!m.count(account[i])){
                        Node* node = new Node(account[i]);
                        node->parent = parent;
                        m.insert({account[i],node});
                        parent->children.insert(node);
                    } else {
                        Node* prev_parent = m[account[i]]->parent;
                        for (Node* child : parent->children){
                            child->parent = prev_parent;
                            prev_parent->children.insert(child);
                        }
                        parent = prev_parent;
                    }
                }  
            }
        }
        vector<vector<string>> ret;
        unordered_map<Node*, int> a;
        int count=0;
        for (auto [key, node]:m){
            if (!a.count(node->parent)){
                a[node->parent] = count;
                count++;
                ret.push_back({node->parent->cur});
            }
            ret[a[node->parent]].push_back(key);
        }
        return ret;
    }
};