class Solution {
public:

    void helper(int i, vector<int>& cur, int n, int k, vector<vector<int>>& ret){
        if (cur.size() == k){
            ret.push_back(cur);
        }

        if (cur.size() > k){
            return;
        }

        for (int j = i; j < n+1; j++){
            cur.push_back(j);
            helper(j+1, cur, n, k, ret);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret = {};
        vector<int> cur = {};
        helper(1, cur, n, k, ret);
        return ret;

    }
};