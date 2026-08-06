class Solution {
public:
    int countSubstrings(string s) {
        int ret = 0;

        for (int i = 0; i< s.size(); i++){
            int left = i;
            int right = i;
            while (left >=0 && right < s.size()&&s[left]==s[right]){
                ret++;
                left--;
                right++;
            }
        }

        for (int i = 1; i< s.size(); i++){
            int left = i-1;
            int right = i;
            while (left >=0 && right < s.size()&&s[left]==s[right]){
                ret++;
                left--;
                right++;
            }
        }
        return ret;
        
    }
};
