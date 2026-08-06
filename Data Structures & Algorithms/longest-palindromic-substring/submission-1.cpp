class Solution {
public:
    string longestPalindrome(string s) {
        int max = 0;
        string ret = "";
        for (int i = 0; i<s.size(); i++){
            int left = i;
            int right = i;
            int cur = 1;
            while (left-1 >= 0 && right+1 < s.size() && s[left-1]==s[right+1]){
                cur+=2;
                left--;
                right++;
            }

            if (cur > max){
                ret = s.substr(left, right-left+1);
                max = cur;
            }
        }
        for (int j = 1; j<s.size(); j++){
            int left = j-1;
            int right = j;
            if (s[left] != s[right]){
                continue;
            }
            int cur = 2;
            while (left-1 >= 0 && right+1 < s.size() && s[left-1]==s[right+1]){
                cur+=2;
                left--;
                right++;
            }
            if (cur > max){
                ret = s.substr(left, right-left+1);
                max = cur;
            }
        }
        return ret;
    }
};
