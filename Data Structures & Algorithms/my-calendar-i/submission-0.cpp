class Node{
public:
    Node* left;
    Node* right;
    int l;
    int r;

    Node(int l, int r): l(l), r(r){
        left = nullptr;
        right = nullptr;
    }
};

class MyCalendar {
public:
    Node* root;
    MyCalendar() {
        root = nullptr;
    }
    
    bool insert(Node* cur, int l, int r){
        if (r < cur->l){
            if (cur->left==nullptr){
                cur->left = new Node(l,r);
                return true;
            }
            return insert(cur->left, l,r);
        }
        else if (l > cur->r){
            if (cur->right == nullptr){
                cur->right = new Node(l, r);
                return true;
            }
            return insert(cur->right, l,r);
        }
        else {
            return false;
        }
    }

    bool book(int startTime, int endTime) {
        int l = startTime;
        int r = endTime-1;
        if (root == nullptr){
            root = new Node(l, r);
            return true;
        }
        return insert(root, l, r);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */