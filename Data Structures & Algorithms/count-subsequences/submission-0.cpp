class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(); int m = t.size();
        vector<int>dp(n+1,1);
        for (int i = 0; i<m; i++){
            vector<int>cur(n+1,0);
            int count = 0;
            for (int j = 0; j<n; j++){
                if (t[i]==s[j]){
                    cur[j+1] = dp[j]+count;
                    count = cur[j+1];
                } else {
                    cur[j+1] = count;
                }
                //cout<<cur[j+1]<<", ";
            }
            //cout<<endl;
            dp = cur;
        }
        return dp[n];
    }
};
