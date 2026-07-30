class Solution {
public:
    void helper(int i, string digits, string cur, vector<string>& ret, unordered_map<int,vector<char>>& m){
        if (cur.size() == digits.size()){
            ret.push_back(cur);
            return;
        }
        vector<char> l = m[digits[i]-'0'];
        for (char c: l){
            cur+=c;
            helper(i+1, digits, cur, ret, m);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()){
            return {};
        }
        unordered_map<int,vector<char>> m = {
            {2,{'a', 'b', 'c'}},
            {3,{'d', 'e', 'f'}},
            {4,{'g', 'h', 'i'}},
            {5,{'j', 'k', 'l'}},
            {6,{'m', 'n', 'o'}},
            {7,{'p', 'q', 'r', 's'}},
            {8,{'t', 'u', 'v'}},
            {9,{'w', 'x', 'y', 'z'}}
        };
        vector<string> ret = {};
        string cur = "";
        helper(0, digits, cur, ret, m);
        return ret;
    }
};
