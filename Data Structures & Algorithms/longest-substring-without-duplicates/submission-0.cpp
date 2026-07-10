class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> m;
        int i = 0; int j = 0;
        int max_len = 0;
        int cur_len = 0;
        while (j < s.size()){
            char cur = s[j];
            while (m.count(cur-'a')){
                m.erase(s[i]-'a');
                i++;
                cur_len--;
            }
            m.insert(cur-'a');
            cur_len++;
            max_len = max(max_len, cur_len);
            j++;
        }
        return max_len;
    }
};
