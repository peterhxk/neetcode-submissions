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
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        TreeNode* cur = root;
        stack<TreeNode*> s;
        s.push(cur);
        while (cur != nullptr || !s.empty()){
            cur = s.top();
            s.pop();
            if (cur != nullptr){
                s.push(cur->right);
                s.push(cur->left);
                ret.push_back(cur->val);
            }
            
        }
        return ret;
    }
};