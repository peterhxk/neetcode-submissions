/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    int i;
    vector<int> nodes;
    BSTIterator(TreeNode* root) {
        i = 0;
        stack<TreeNode*> s;
        TreeNode* cur;
        cur = root;
        while (!s.empty() || cur != nullptr){
            if (cur != nullptr){
                s.push(cur);
                cur = cur->left;
            }
            else{
                cur = s.top();
                s.pop();
                nodes.push_back(cur->val);
                cur = cur->right;
            }
        }

    }
    
    int next() {
        return (nodes[i++]);
        
    }
    
    bool hasNext() {
        return (i<nodes.size());
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */