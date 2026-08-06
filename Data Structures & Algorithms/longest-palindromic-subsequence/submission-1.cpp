class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int>dp (n+1, 0);
        string a = s;
        reverse(s.begin(), s.end());
        for (int i = 0; i< n; i++){
            vector<int> cur(n+1, 0);
            for (int j = 0; j<n; j++){
                if (a[i]==s[j]){
                    cur[j+1] = max({cur[j], dp[j]+1, dp[j+1]});
                } else {
                    cur[j+1] = max(cur[j], dp[j+1]);
                }
                //cout<<cur[j+1]<<", ";
            }
            //cout<<endl;
            dp = cur;
        }
        return dp[n];
    }
};