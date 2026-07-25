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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<pair<TreeNode*, bool>> s;
        s.push({root,false});
        while (!s.empty()){
            auto n = s.top();
            s.pop();
            TreeNode* node = get<0>(n);
            if (node != nullptr){
                if (get<1>(n)==true){
                    ret.push_back(node->val);
                }
                else{
                    s.push({node, true});
                    s.push({node->right,false});
                    s.push({node->left, false});
                }
            }
        }
        return ret;
    }
};